// Задание 1.1: Вывод результатов выражений
const results = [
    `true + false = ${true + false}`,
    `12 / "6" = ${12 / "6"}`,
    `"number" + 15 + 3 = ${"number" + 15 + 3}`,
    `15 + 3 + "number" = ${15 + 3 + "number"}`,
    `'1' > null = ${'1' > null} (1 > 0)`,
    `'true' == true = ${'true' == true}`,
    `false == 'false' = ${false == 'false'}`,
    `null == '' = ${null == ''}`
];
document.getElementById('output1').innerHTML = results.join('<br>');

// Задание 1.2: Проверка типа переменной
const testVar = "Hello World!";
let typeMessage;

if (typeof testVar === 'string') {
    typeMessage = "Это строка";
} else if (typeof testVar === 'number') {
    typeMessage = "Это число";
} else if (typeof testVar === 'boolean') {
    typeMessage = "Это логическое значение";
} else {
    typeMessage = "Это другой тип: " + typeof testVar;
}

document.getElementById('output2').textContent = 
    `Переменная: "${testVar}", Тип: ${typeof testVar} - ${typeMessage}`;

// Задание 1.3: Приветствие по знаку зодиака
function getZodiacSign() {
    const sign = prompt("Введите ваш знак зодиака:").toLowerCase();
    let greeting;
    
    switch(sign) {
        case 'овен': greeting = "Огненный привет, Овен!"; break;
        case 'телец': greeting = "Земной поклон, Телец!"; break;
        case 'близнецы': greeting = "Воздушный поцелуй, Близнецы!"; break;
        case 'рак': greeting = "Водные просторы ждут вас, Рак!"; break;
        case 'лев': greeting = "Солнечный луч для Льва!"; break;
        case 'дева': greeting = "Земные благословения, Дева!"; break;
        case 'весы': greeting = "Гармонии и баланса, Весы!"; break;
        case 'скорпион': greeting = "Тайны Вселенной для Скорпиона!"; break;
        case 'стрелец': greeting = "Стрела удачи в ваших руках!"; break;
        case 'козерог': greeting = "Горные вершины ждут, Козерог!"; break;
        case 'водолей': greeting = "Инновации и прогресс, Водолей!"; break;
        case 'рыбы': greeting = "Океан возможностей для Рыб!"; break;
        default: greeting = "Добро пожаловать, звездный странник!";
    }
    
    document.getElementById('output3').textContent = greeting;
}

// Задание 1.4: Сумма чисел (3 цикла)
function calculateSum() {
    const n = parseInt(document.getElementById('numberN').value);
    if (isNaN(n)) {
        document.getElementById('output4').textContent = "Пожалуйста, введите число!";
        return;
    }
    
    // Цикл for
    let sumFor = 0;
    for(let i = 1; i <= n; i++) sumFor += i;
    
    // Цикл while
    let sumWhile = 0, j = 1;
    while(j <= n) sumWhile += j++;
    
    // Цикл do...while
    let sumDoWhile = 0, k = 1;
    do { sumDoWhile += k++ } while(k <= n);
    
    document.getElementById('output4').innerHTML = `
        for: 1+2+...+${n} = ${sumFor}<br>
        while: 1+2+...+${n} = ${sumWhile}<br>
        do...while: 1+2+...+${n} = ${sumDoWhile}
    `;
}

// Задание 1.5: Четные/нечетные числа
let numbersOutput = "";
for(let i = 0; i <= 15; i++) {
    numbersOutput += `${i} - ${i % 2 === 0 ? 'четное' : 'нечетное'}<br>`;
}
document.getElementById('output5').innerHTML = numbersOutput;

// Задание 1.6: Проверка числа (>5)
function checkNumber() {
    let number;
    do {
        number = prompt("Введите число больше 5:");
        // Если пользователь нажал "Отмена"
        if (number === null) {
            document.getElementById('output6').textContent = "Вы отменили ввод.";
            return;
        }
        number = Number(number);
    } while (isNaN(number) || number <= 5);

    document.getElementById('output6').textContent = `Поздравляем! Вы ввели ${number}, что больше 5.`;
}

// Задание 1.7: Треугольник из звёздочек
let triangle = "";
for (let i = 1; i <= 4; i++) {
    for (let j = 1; j <= i; j++) {
        triangle += '* ';
    }
    triangle += '<br>';
}
document.getElementById('output7').innerHTML = triangle;

// 2.1. Создание массива тремя способами
const array1 = [1, 2, 3, 4, 5]; // литерал массива
const array2 = new Array('a', 'b', 'c', 'd', 'e'); // конструктор Array
const array3 = Array.from({length: 5}, (_, i) => i * 10); // метод Array.from

// Выберем первый массив для дальнейшей работы
let workingArray = [...array1];

// Отображаем информацию о массиве
function displayArrayInfo() {
    let info = `
        <p><strong>Массив 1:</strong> [${array1.join(', ')}]</p>
        <p><strong>Массив 2:</strong> [${array2.join(', ')}]</p>
        <p><strong>Массив 3:</strong> [${array3.join(', ')}]</p>
        <p><strong>Рабочий массив:</strong> [${workingArray.join(', ')}]</p>
        <p><strong>5-й элемент:</strong> ${workingArray[4]}</p>
    `;
    
    // Изменяем 5-й элемент
    workingArray[4] = 'изменено';
    info += `<p><strong>После изменения 5-го элемента:</strong> [${workingArray.join(', ')}]</p>`;
    
    // Длина массива
    info += `<p><strong>Длина массива:</strong> ${workingArray.length}</p>`;
    
    // Вывод элементов двумя способами
    info += `<p><strong>Элементы (способ 1 - for):</strong> `;
    for (let i = 0; i < workingArray.length; i++) {
        info += workingArray[i] + (i < workingArray.length - 1 ? ', ' : '');
    }
    info += `</p><p><strong>Элементы (способ 2 - forEach):</strong> `;
    workingArray.forEach((item, index) => {
        info += item + (index < workingArray.length - 1 ? ', ' : '');
    });
    info += '</p>';
    
    document.getElementById('arrayInfo').innerHTML = info;
}

// 2.2. Операции с массивом
function performOperation() {
    const operation = document.getElementById('operation').value;
    let result = '';
    
    switch (operation) {
        case '1': // Добавление в начало
            const startElement = prompt('Введите элемент для добавления в начало:');
            if (startElement !== null) {
                workingArray.unshift(startElement);
                result = `Добавлен элемент "${startElement}" в начало массива`;
            }
            break;
            
        case '2': // Добавление в конец
            const endElement = prompt('Введите элемент для добавления в конец:');
            if (endElement !== null) {
                workingArray.push(endElement);
                result = `Добавлен элемент "${endElement}" в конец массива`;
            }
            break;
            
        case '3': // Удаление первого элемента
            if (workingArray.length > 0) {
                const removedFirst = workingArray.shift();
                result = `Удален первый элемент: "${removedFirst}"`;
            } else {
                result = 'Массив пуст!';
            }
            break;
            
        case '4': // Удаление последнего элемента
            if (workingArray.length > 0) {
                const removedLast = workingArray.pop();
                result = `Удален последний элемент: "${removedLast}"`;
            } else {
                result = 'Массив пуст!';
            }
            break;
            
        case '5': // Добавление по индексу
            const insertIndex = prompt('Введите индекс для вставки:');
            const insertElement = prompt('Введите элемент для вставки:');
            
            if (insertIndex !== null && insertElement !== null) {
                const index = parseInt(insertIndex);
                if (!isNaN(index) && index >= 0 && index <= workingArray.length) {
                    workingArray.splice(index, 0, insertElement);
                    result = `Добавлен элемент "${insertElement}" на позицию ${index}`;
                } else {
                    result = 'Некорректный индекс!';
                }
            }
            break;
            
        case '6': // Удаление по индексу
            const removeIndex = prompt('Введите индекс для удаления:');
            
            if (removeIndex !== null) {
                const index = parseInt(removeIndex);
                if (!isNaN(index) && index >= 0 && index < workingArray.length) {
                    const removed = workingArray.splice(index, 1)[0];
                    result = `Удален элемент "${removed}" с позиции ${index}`;
                } else {
                    result = 'Некорректный индекс!';
                }
            }
            break;
            
        case '7': // Изменение по индексу
            const changeIndex = prompt('Введите индекс для изменения:');
            const newElement = prompt('Введите новое значение элемента:');
            
            if (changeIndex !== null && newElement !== null) {
                const index = parseInt(changeIndex);
                if (!isNaN(index) && index >= 0 && index < workingArray.length) {
                    const oldElement = workingArray[index];
                    workingArray[index] = newElement;
                    result = `Элемент на позиции ${index} изменен с "${oldElement}" на "${newElement}"`;
                } else {
                    result = 'Некорректный индекс!';
                }
            }
            break;
            
        default:
            result = 'Выберите операцию из списка!';
    }
    
    document.getElementById('operationResult').textContent = result;
    document.getElementById('currentArray').innerHTML = 
        `<strong>Текущий массив:</strong> [${workingArray.join(', ')}] (длина: ${workingArray.length})`;
}

// Инициализация при загрузке страницы
displayArrayInfo();
document.getElementById('currentArray').innerHTML = 
    `<strong>Текущий массив:</strong> [${workingArray.join(', ')}] (длина: ${workingArray.length})`;


// Задание 3.1: Площадь треугольника
function calculateArea() {
    const a = parseFloat(document.getElementById('base').value);
    const b = parseFloat(document.getElementById('height').value);
    const area = (a * b) / 2;
    document.getElementById('areaResult').textContent = `Площадь треугольника: ${area}`;
}

// Задание 3.2: Произведение случайных чисел
function multiplyRandom() {
    const num1 = Math.floor(Math.random() * 51);
    const num2 = Math.floor(Math.random() * 51);
    const product = num1 * num2;
    document.getElementById('randomResult').textContent = 
        `${num1} * ${num2} = ${product}`;
}

// Задание 3.4: Часы
function updateClock() {
    const now = new Date();
    const hours = String(now.getHours()).padStart(2, '0');
    const minutes = String(now.getMinutes()).padStart(2, '0');
    const seconds = String(now.getSeconds()).padStart(2, '0');
    document.getElementById('clock').textContent = `${hours}:${minutes}:${seconds}`;
}

setInterval(updateClock, 1000);
updateClock();

// Задание 3.5: Смена картинки
let isImageChanged = false;
const originalImage = "1.jpg";
const changedImage = "2.jpg";


function changeImage() {
    const img = document.getElementById('changeableImage');
    
    if (isImageChanged) {
        img.src = originalImage;
        img.style.border = "none";
        img.style.borderRadius = "0";
        img.style.boxShadow = "none";
    } else {
        img.src = changedImage;
        img.style.border = "3px solid #3498db";
        img.style.borderRadius = "10px";
        img.style.boxShadow = "0 4px 8px rgba(0,0,0,0.2)";
    }
    
    isImageChanged = !isImageChanged;
}

// Задание 3.6: Создание карточек
const cardData = [
    {
        title: "Ноутбук",
        text: "Мощный игровой ноутбук с процессором Intel Core i7",
        image: "laptop.jpg"
    },
    {
        title: "Смартфон",
        text: "Флагманский смартфон с камерой 108 Мп",
        image: "smartphone.jpg"
    },
    {
        title: "Наушники",
        text: "Беспроводные наушники с шумоподавлением",
        image: "headphone.jpg"
    }
];

function createCard() {
    const container = document.getElementById('cardsContainer');
    const randomCard = cardData[Math.floor(Math.random() * cardData.length)];
    
    const card = document.createElement('div');
    card.className = 'card';
    
    card.innerHTML = `
        <img src="${randomCard.image}" alt="${randomCard.title}">
        <div class="card-content">
            <h3>${randomCard.title}</h3>
            <p>${randomCard.text}</p>
        </div>
    `;
    
    container.appendChild(card);
}

// Задание 3.7: Приветствие
function saveName() {
    const name = document.getElementById('userName').value.trim();
    if (name) {
        localStorage.setItem('userName', name);
        showGreeting(name);
    }
}

function showGreeting(name) {
    document.getElementById('greeting').textContent = `Привет, ${name}!`;
}

// Проверяем сохраненное имя при загрузке
window.onload = function() {
    const savedName = localStorage.getItem('userName');
    if (savedName) {
        showGreeting(savedName);
        document.getElementById('userName').value = savedName;
    }
};

// Задание 3.8: Тест по JavaScript
const testQuestions = [
    {
        question: "Какое ключевое слово используется для объявления переменной в ES6?",
        answers: ["var", "let", "variable", "const"],
        correct: 1
    },
    {
        question: "Что возвращает метод Array.map()?",
        answers: ["Первый элемент массива", "Новый массив", "Последний элемент массива", "Сумму элементов"],
        correct: 1
    },
    {
        question: "Какой оператор выполняет строгое сравнение?",
        answers: ["==", "===", "=", "!="],
        correct: 1
    },
    {
        question: "Как добавить новый элемент в конец массива?",
        answers: ["array.unshift()", "array.push()", "array.pop()", "array.shift()"],
        correct: 1
    },
    {
        question: "Что такое DOM в JavaScript?",
        answers: ["Тип данных", "Объектная модель документа", "Среда выполнения", "Библиотека"],
        correct: 1
    }
];

let currentQuestion = 0;
let userAnswers = [];

function startTest() {
    document.getElementById('testContainer').style.display = 'block';
    document.getElementById('nextButton').textContent = 'Следующий вопрос';
    currentQuestion = 0;
    userAnswers = [];
    showQuestion();
}

function showQuestion() {
    const question = testQuestions[currentQuestion];
    document.getElementById('question').textContent = `Вопрос ${currentQuestion + 1}: ${question.question}`;
    
    const answersContainer = document.getElementById('answers');
    answersContainer.innerHTML = '';
    
    question.answers.forEach((answer, index) => {
        const answerBtn = document.createElement('div');
        answerBtn.className = 'test-answer';
        answerBtn.textContent = answer;
        answerBtn.onclick = () => selectAnswer(index);
        answersContainer.appendChild(answerBtn);
    });
}

function selectAnswer(index) {
    userAnswers[currentQuestion] = index;
    
    // Убираем выделение у всех ответов
    document.querySelectorAll('.test-answer').forEach(btn => {
        btn.style.backgroundColor = '';
    });
    
    // Выделяем выбранный ответ
    event.target.style.backgroundColor = '#e1f5fe';
}

function nextQuestion() {
    if (userAnswers[currentQuestion] === undefined) {
        alert("Выберите ответ!");
        return;
    }
    
    currentQuestion++;
    
    if (currentQuestion < testQuestions.length) {
        showQuestion();
    } else {
        showTestResult();
    }
}

function showTestResult() {
    document.getElementById('testContainer').style.display = 'none';
    
    let correctCount = 0;
    let resultHTML = "<h3>Результаты теста:</h3><ol>";
    
    testQuestions.forEach((question, index) => {
        const userAnswer = userAnswers[index];
        const isCorrect = userAnswer === question.correct;
        
        if (isCorrect) correctCount++;
        
        resultHTML += `
            <li>
                <strong>${question.question}</strong><br>
                Ваш ответ: ${question.answers[userAnswer]} 
                (${isCorrect ? '<span style="color:green">Верно</span>' : '<span style="color:red">Неверно</span>'})<br>
                Правильный ответ: ${question.answers[question.correct]}
            </li>
        `;
    });
    
    resultHTML += `</ol><p><strong>Итог: ${correctCount} из ${testQuestions.length}</strong></p>`;
    document.getElementById('testResult').innerHTML = resultHTML;
}