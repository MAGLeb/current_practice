import { api } from '../api/api';
import { cardList } from '../cardList';

const addForm = document.forms.new;
const popup = document.querySelector('.popup');

export class Popup {
    constructor (popup) {
      this.popup = popup;  
      
      this.close = this.close.bind(this);
      this.submit = this.submit.bind(this);
  
      this.popup.querySelector('.popup__close').addEventListener('click', this.close);
      this.popup.querySelector('.button').addEventListener('click', this.submit);
    }
  
    open() {
      this.popup.classList.add('popup_is-opened');
    }
  
    close() {
      this.popup.classList.remove('popup_is-opened');
    }
  
    submit() {
      event.preventDefault();
      addForm.querySelector("button").textContent = "Загрузка...";
      addForm.querySelector("button").style.fontSize = "24px";
      api.addNewCard(addForm.elements.name.value, addForm.elements.link.value)
        .then((res) => {
          cardList.addCard(res.name, res.link, res.likes.length, res._id);
          this.close();
          addForm.elements.name.value = '';
          addForm.elements.link.value = '';
        })
        .catch(err => console.log(err))
        .finally(() => {
          addForm.querySelector("button").textContent = "+";
          addForm.querySelector("button").style.fontSize = "36px";
          popup.querySelector('button').setAttribute('disabled', 'true');
          popup.querySelector('button').classList.remove('popup__button-active');
        })
    }
};

export const popupAdd = new Popup(document.querySelector('.popup'));