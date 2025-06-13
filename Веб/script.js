document.addEventListener('DOMContentLoaded', function() {
    // Фиксированная дата окончания (через 18 дней)
    const endDate = new Date();
    endDate.setDate(endDate.getDate() + 18);
    
    let timerInterval;
    
    // Функция для обновления таймера
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
        
        // Рассчитываем оставшееся время
        const days = Math.floor(diff / (1000 * 60 * 60 * 24));
        const hours = Math.floor((diff % (1000 * 60 * 60 * 24)) / (1000 * 60 * 60));
        const minutes = Math.floor((diff % (1000 * 60 * 60)) / (1000 * 60));
        const seconds = Math.floor((diff % (1000 * 60)) / 1000);
        
        // Получаем все элементы для обновления
        const timerNumbers = document.querySelectorAll('.timer-number');
        
        // Обновляем элементы на странице
        if (timerNumbers.length >= 4) {
            timerNumbers[0].textContent = days.toString().padStart(2, '0');
            timerNumbers[1].textContent = hours.toString().padStart(2, '0');
            timerNumbers[2].textContent = minutes.toString().padStart(2, '0');
            timerNumbers[3].textContent = seconds.toString().padStart(2, '0');
        }
    }
    
    // Запускаем таймер
    updateTimer();
    timerInterval = setInterval(updateTimer, 1000);
    
    // Валидация email
    function validateEmail(email) {
        const re = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
        return re.test(email);
    }
    
    // Обработчик для кнопки "Подписаться"
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
    
    // Анимация для кнопок
    const buttons = document.querySelectorAll('.btn-primary, .btn-order, .submit-btn, .btn-bio');
    
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
});