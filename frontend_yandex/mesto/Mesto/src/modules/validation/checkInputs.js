const popupButton = document.querySelector('.popup__button-save');

export default function checkInputs(form) {
    const input = Array.from(form.querySelectorAll('input'));
    const button = form.querySelector('button');
    const error = Array.from(form.querySelectorAll('.popup__error'));
  
    if (input[0].value !== '' && input[1].value !== '') {
        popupButton.classList.add('popup__button-active');
    } 
  
    input.forEach((item, index)=> {
        item.addEventListener('input', () => {
            if (item.classList.contains('popup__input_type_link-url')) {
                if (!item.value.startsWith('http') || item.value < 4) {
                    error[index].classList.add('popup__error-active');
                    error[index].textContent = 'Здесь должна быть ссылка';
                } else if (item.classList.contains('popup__input_type_link-url')) {
                    error[index].classList.remove('popup__error-active');
                }
            }
      
            if (!item.classList.contains('popup__input_type_link-url') && item.value.length > 30) {
                error[index].classList.add('popup__error-active');
                error[index].textContent = 'Должно быть от 2 до 30 символов';
            } else if (!item.classList.contains('popup__input_type_link-url') && item.value.length <= 30) {
                error[index].classList.remove('popup__error-active');
            }
      
            if (item.value === '') {
                error[index].textContent = 'Это обязательное поле';
                error[index].classList.add('popup__error-active');
            } else if (item.value.length === 1) {  
                error[index].classList.add('popup__error-active');
                error[index].textContent = 'Должно быть от 2 до 30 символов';
            } else if (item.value.length <= 2) {
                error[index].classList.remove('popup__error-active');
            }
      
            if (input[0].value !== '' && input[1].value !== '' && !error[0].classList.contains('popup__error-active') && !error[1].classList.contains('popup__error-active')) {
                button.classList.add('popup__button-active');
                button.removeAttribute('disabled');
            } else {
                button.classList.remove('popup__button-active');
                button.setAttribute('disabled', 'true');
            }
        });
    });
}