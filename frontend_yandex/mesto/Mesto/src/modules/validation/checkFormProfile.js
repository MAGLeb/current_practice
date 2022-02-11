export default function checkFormProfile(form) {
    const input = form.link;
    const button = form.querySelector('button');
    const error = form.querySelector('.popup__error');
  
    if(input.value === '') {
        button.classList.remove('popup__button-active');
    }
  
    input.addEventListener('input', () => {
        if(input.value.startsWith("http")) {
            error.classList.remove('popup__error-active');
            button.classList.add('popup__button-active');
            button.removeAttribute('disabled');
        } else {
            error.classList.add('popup__error-active');
            button.classList.remove('popup__button-active');
            button.setAttribute('disabled', 'true');
        }
    })
};