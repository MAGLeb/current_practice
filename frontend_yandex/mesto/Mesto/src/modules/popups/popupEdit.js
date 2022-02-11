import { api } from '../api/api';
import { Popup } from './popup';

const changeForm = document.forms.change;
const userName = document.querySelector('.user-info__name');
const userJob = document.querySelector('.user-info__job');

class PopupEdit extends Popup {
    constructor(popup) {
      super(popup);
    }
  
    open() {
      super.open();
      
      changeForm.elements.name.value = userName.textContent;
      changeForm.elements.job.value = userJob.textContent;
    }
  
    submit(event) {
      event.preventDefault();
      changeForm.querySelector(".popup__button-save").textContent = "Загрузка...";
  
      api.editProfile(changeForm.elements.name.value, changeForm.elements.job.value)
      .then(() => {
        userName.textContent = changeForm.elements.name.value;
        userJob.textContent = changeForm.elements.job.value;
        super.close();      
      })
      .catch(err => console.log(err))
      .finally(() => {
        changeForm.querySelector(".popup__button-save").textContent = "Сохранить";
      });
    }
};

export const popupEdit = new PopupEdit(document.querySelector('.popup.popup-edit'));