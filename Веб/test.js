// 1. Приветствие пользователя и сохранение имени
const userNameInput = document.getElementById('userName'); //Поле ввода
const usernameDisplay = document.getElementById('usernameDisplay'); //Блок отображения
const startBtn = document.getElementById('startBtn');//кнопка начать

// Проверяем, есть ли сохраненное имя
const savedName = localStorage.getItem('userName');
if (savedName) {
    usernameDisplay.textContent = savedName; //Показывает имя из памяти
}
//кнопка "Начать"
startBtn.addEventListener('click', function() {
    const userName = userNameInput.value.trim();
    if (userName) {
        // Сохраняем имя пользователя
        localStorage.setItem('userName', userName);
        usernameDisplay.textContent = userName;
        
        // Показываем тест
        document.getElementById('welcomeContainer').style.display = 'none';
        document.getElementById('testContainer').style.display = 'block';
        
        // Генерируем вопросы
        generateQuestions();
    } else {
        alert('Пожалуйста, введите ваше имя');
    }
});

// 2. Переключение темы
const themeToggle = document.getElementById('themeToggle');

// Проверяем сохраненную тему
if (localStorage.getItem('theme') === 'dark') {
    document.body.classList.add('dark-theme');
    themeToggle.textContent = 'Светлая тема';
}
//обработка переключения
themeToggle.addEventListener('click', function() {
    if (document.body.classList.contains('dark-theme')) {
            //Переключение на светлую
        document.body.classList.remove('dark-theme');
        themeToggle.textContent = 'Тёмная тема';
        localStorage.setItem('theme', 'light');
    } else {
        //переключение на темную
        document.body.classList.add('dark-theme');
        themeToggle.textContent = 'Светлая тема';
        localStorage.setItem('theme', 'dark');
    }
});

// 3. Тест на знание компьютеров
const questions = [
    {
        question: "Какой компонент отвечает за обработку графики?",
        options: ["Процессор", "Видеокарта", "Оперативная память", "Жесткий диск"],
        answer: 1
    },
    {
        question: "Какой тип памяти используется для долговременного хранения?",
        options: ["SSD", "RAM", "Кэш-память", "BIOS"],
        answer: 0
    },
    {
        question: "Что НЕ важно при выборе блока питания?",
        options: ["Мощность", "Эффективность", "Цвет подсветки", "Разъемы"],
        answer: 2
    },
    {
        question: "Что означает аббревиатура SSD?",
        options: ["Super Speed Drive", "Solid State Drive", "System Storage Device", "Secondary Storage Disk"],
        answer: 1
    },
    {
        question: "Какой разъем используется для монитора?",
        options: ["USB-C", "HDMI", "Ethernet", "SATA"],
        answer: 1
    },
    {
        question: "Какая функция ОЗУ (RAM)?",
        options: ["Хранение ОС", "Временное хранение данных", "Обработка графики", "Управление питанием"],
        answer: 1
    },
    {
        question: "Что такое материнская плата?",
        options: ["Устройство хранения", "Основная плата компьютера", "Охлаждение процессора", "Плата видеокарты"],
        answer: 1
    },
    {
        question: "Что охлаждает процессор?",
        options: ["Блок питания", "Видеокарта", "Кулер", "Жесткий диск"],
        answer: 2
    },
    {
        question: "Что измеряется в гигагерцах (GHz)?",
        options: ["Объем памяти", "Объем диска", "Частота процессора", "Скорость интернета"],
        answer: 2
    },
    {
        question: "Какой компонент хранит BIOS?",
        options: ["Жесткий диск", "Оперативная память", "Микросхема на материнке", "Процессор"],
        answer: 2
    }
];

let currentQuestion = 0; //текущий вопрос
let userAnswers = new Array(questions.length).fill(null); //массив ответов

function generateQuestions() {
    const container = document.getElementById('questionsContainer');
    container.innerHTML = ''; //очистка контейнера
    
    questions.forEach((q, index) => {
        const questionDiv = document.createElement('div');
        questionDiv.className = 'question';
        questionDiv.style.display = index === 0 ? 'block' : 'none'; //показывает только первый 
        questionDiv.dataset.index = index; //сохранение индекса
        
        questionDiv.innerHTML = `
            <div class="question-text">${index + 1}. ${q.question}</div>
            <div class="options">
                ${q.options.map((opt, i) => `
                    <div class="option" data-option="${i}">${opt}</div>
                `).join('')}
            </div>
        `;
        
        container.appendChild(questionDiv);
        
        // Добавляем обработчики для вариантов ответа
        questionDiv.querySelectorAll('.option').forEach(option => {
            option.addEventListener('click', function() {
                const optionIndex = parseInt(this.dataset.option);
                //сохранение ответа пользователя
                userAnswers[index] = optionIndex;
                
                // Снимаем выделение со всех вариантов
                this.parentElement.querySelectorAll('.option').forEach(opt => {
                    opt.classList.remove('selected');
                });
                
                // Выделяем выбранный вариант
                this.classList.add('selected');
            });
        });
    });
}

// Навигация по вопросам
const prevBtn = document.getElementById('prevBtn');
const nextBtn = document.getElementById('nextBtn');
const submitBtn = document.getElementById('submitBtn');

prevBtn.addEventListener('click', function() {
    if (currentQuestion > 0) {
        //скрытие текущего вопроса
        document.querySelector(`.question[data-index="${currentQuestion}"]`).style.display = 'none';
        currentQuestion--;
        //отображение предыдущего вопроса
        document.querySelector(`.question[data-index="${currentQuestion}"]`).style.display = 'block';
        
        prevBtn.disabled = currentQuestion === 0;
        nextBtn.style.display = 'block';
        submitBtn.style.display = 'none';
    }
});

nextBtn.addEventListener('click', function() {
    if (currentQuestion < questions.length - 1) {
        //скрытие текущего вопроса
        document.querySelector(`.question[data-index="${currentQuestion}"]`).style.display = 'none';
        currentQuestion++;
        //отображение следущего вопроса
        document.querySelector(`.question[data-index="${currentQuestion}"]`).style.display = 'block';
        
        prevBtn.disabled = false;
        
        if (currentQuestion === questions.length - 1) {
            nextBtn.style.display = 'none';
            submitBtn.style.display = 'block'; //кнопка завершения
        }
    }
});

// Завершение теста
submitBtn.addEventListener('click', function() {
    calculateResults();
});

function calculateResults() {
    let correctCount = 0; //счетчик правильных ответов
    const results = []; //массив для результатов
    
    //проверка каждого ответа
    questions.forEach((q, index) => {
        // проверка правильного ответа
        const isCorrect = userAnswers[index] === q.answer;
        //если ответ правильный, то счетчик увеличивается
        if (isCorrect) correctCount++;
        //сохранение детальной информации о вопросе
        results.push({
            question: q.question,
            userAnswer: q.options[userAnswers[index]],
            correctAnswer: q.options[q.answer],
            isCorrect: isCorrect
        });
    });
    
    //расчет ответов (правильные/на все вопросы и умножаем на 100 чтобы было в %)
    const score = Math.round((correctCount / questions.length) * 100);
    
    // Сохраняем результат
    const testResult = {
        userName: localStorage.getItem('userName'),
        date: new Date().toLocaleString(),
        score: score
    };
    localStorage.setItem('testResult', JSON.stringify(testResult));
    
    // Показываем результаты
    showResults(results);
}

function showResults(results) {
    //контейнер для результатов
    const resultsList = document.getElementById('resultsList');
    //очистка контейнера от предыдущих ответов
    resultsList.innerHTML = '';
    
    
    // Генерация элементов результатов
    results.forEach((result, index) => {
        const resultItem = document.createElement('div');
        //установка класса в зависимости от ответа
        resultItem.className = `result-item ${result.isCorrect ? 'correct' : 'incorrect'}`;
        //подробная информация, выводимая пользователю
        resultItem.innerHTML = `
            <p><strong>${index + 1}. ${result.question}</strong></p>
            <p>Ваш ответ: ${result.userAnswer}</p>
            <p>Правильный ответ: ${result.correctAnswer}</p>
            <p>${result.isCorrect ? '✅ Верно' : '❌ Неверно'}</p>
        `;
        //добавление в контейнер
        resultsList.appendChild(resultItem);
    });
    
    document.getElementById('testContainer').style.display = 'none';
    document.getElementById('resultContainer').style.display = 'block';
}

// Перезапуск теста
document.getElementById('restartBtn').addEventListener('click', function() {
    currentQuestion = 0;
    userAnswers = new Array(questions.length).fill(null);
    
    document.getElementById('resultContainer').style.display = 'none';
    document.getElementById('testContainer').style.display = 'block';
    
    generateQuestions();
    prevBtn.disabled = true;
    nextBtn.style.display = 'block';
    submitBtn.style.display = 'none';
});

// 4. Всплывающее окно с результатами
const usernameDisplayElem = document.getElementById('usernameDisplay');
const resultsPopup = document.getElementById('resultsPopup');
const overlay = document.getElementById('overlay');
const closePopup = document.getElementById('closePopup');
const popupResults = document.getElementById('popupResults');

usernameDisplayElem.addEventListener('click', function() {
    //получение сохраненного результата
    const savedResult = localStorage.getItem('testResult');
    //проверка наличия сохраненного результата
    if (savedResult) {
        const result = JSON.parse(savedResult);
        //создание видимого текста для пользователя
        popupResults.innerHTML = `
            <p><strong>Имя:</strong> ${result.userName}</p>
            <p><strong>Дата:</strong> ${result.date}</p>
            <p><strong>Результат:</strong> ${result.score}%</p>
        `;
    } else {
        popupResults.innerHTML = '<p>Вы еще не проходили тест</p>';
    }
    //отображение всплывающего окна
    resultsPopup.style.display = 'block';
    overlay.style.display = 'block';
});
//Закрытие окна при нажатии на крестик
closePopup.addEventListener('click', function() {
    resultsPopup.style.display = 'none';
    overlay.style.display = 'none';
});
//закритие при нажатии на пустое поле вне попапа
overlay.addEventListener('click', function() {
    resultsPopup.style.display = 'none';
    overlay.style.display = 'none';
});