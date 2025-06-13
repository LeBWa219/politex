document.addEventListener('DOMContentLoaded', function() {
    // ================= ТАЙМЕР =================
    const endDate = new Date();
    endDate.setDate(endDate.getDate() + 18);
    
    let timerInterval;
    
    function updateTimer() {
        const now = new Date();
        const diff = endDate - now;
        
        if (diff <= 0) {
            clearInterval(timerInterval);
            document.querySelectorAll('.timer-number').forEach(el => {
                el.textContent = "00";
            });
            return;
        }
        
        const days = Math.floor(diff / (1000 * 60 * 60 * 24));
        const hours = Math.floor((diff % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
        const minutes = Math.floor((diff % (1000 * 60 * 60)) / (1000 * 60));
        const seconds = Math.floor((diff % (1000 * 60)) / 1000);
        
        const timerNumbers = document.querySelectorAll('.timer-number');
        
        if (timerNumbers.length >= 4) {
            timerNumbers[0].textContent = days.toString().padStart(2, '0');
            timerNumbers[1].textContent = hours.toString().padStart(2, '0');
            timerNumbers[2].textContent = minutes.toString().padStart(2, '0');
            timerNumbers[3].textContent = seconds.toString().padStart(2, '0');
        }
    }
    
    updateTimer();
    timerInterval = setInterval(updateTimer, 1000);
    
    // ================= ВАЛИДАЦИЯ EMAIL =================
    function validateEmail(email) {
        const re = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
        return re.test(email);
    }
    
    const submitBtn = document.querySelector('.submit-btn');
    if (submitBtn) {
        submitBtn.addEventListener('click', function() {
            const emailInput = document.querySelector('.email-input');
            const email = emailInput.value;
            
            if (validateEmail(email)) {
                alert(`Спасибо за подписку! На адрес ${email} будут приходить обновления курса.`);
                emailInput.value = '';
            } else {
                alert('Пожалуйста, введите корректный email адрес!');
            }
        });
    }
    
    // ================= АНИМАЦИЯ КНОПОК =================
    const buttons = document.querySelectorAll('.btn-primary, .btn-order, .submit-btn, .btn-bio, .login-btn');
    
    buttons.forEach(button => {
        button.addEventListener('mouseenter', function() {
            this.style.transform = 'scale(1.05)';
            this.style.opacity = '0.9';
        });
        
        button.addEventListener('mouseleave', function() {
            this.style.transform = 'scale(1)';
            this.style.opacity = '1';
        });
    });
    
    // ================= МОДАЛЬНОЕ ОКНО =================
    const loginModal = document.getElementById('loginModal');
    const closeModal = document.querySelector('.close-modal');
    const loginForm = document.getElementById('loginForm');
    const desktopBtn = document.querySelector('.desktop-btn');
    const mobileBtn = document.querySelector('.mobile-btn');
    
    // Открытие модального окна
    if (desktopBtn) {
        desktopBtn.addEventListener('click', function(e) {
            e.preventDefault();
            loginModal.style.display = 'flex';
        });
    }
    
    if (mobileBtn) {
        mobileBtn.addEventListener('click', function(e) {
            e.preventDefault();
            loginModal.style.display = 'flex';
        });
    }
    
    // Закрытие модального окна
    closeModal.addEventListener('click', function() {
        loginModal.style.display = 'none';
    });
    
    // Закрытие при клике вне окна
    window.addEventListener('click', function(event) {
        if (event.target === loginModal) {
            loginModal.style.display = 'none';
        }
    });
    
    // Обработка формы входа
    loginForm.addEventListener('submit', function(e) {
        e.preventDefault();
        
        const username = document.getElementById('username').value;
        const password = document.getElementById('password').value;
        const usernameError = document.getElementById('usernameError');
        const passwordError = document.getElementById('passwordError');
        
        // Сброс сообщений об ошибках
        usernameError.style.display = 'none';
        passwordError.style.display = 'none';
        
        // Валидация
        let isValid = true;
        
        if (!username) {
            usernameError.style.display = 'block';
            isValid = false;
        }
        
        if (!password) {
            passwordError.style.display = 'block';
            isValid = false;
        }
        
        if (isValid) {
            // Здесь можно добавить реальную логику входа
            alert(`Добро пожаловать, ${username}!`);
            loginModal.style.display = 'none';
            
            // Очищаем форму
            loginForm.reset();
        }
    });
    
    // ================= ПЛАВНАЯ ПРОКРУТКА =================
    document.querySelectorAll('a[href^="#"]').forEach(anchor => {
        anchor.addEventListener('click', function (e) {
            e.preventDefault();
            
            const targetId = this.getAttribute('href');
            if (targetId === '#') return;
            
            const targetElement = document.querySelector(targetId);
            if (targetElement) {
                window.scrollTo({
                    top: targetElement.offsetTop - 80,
                    behavior: 'smooth'
                });
            }
        });
    });
});