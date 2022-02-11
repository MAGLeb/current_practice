import "./style.css";
import { api } from './modules/api/api';
import { popupAdd } from './modules/popups/popup';
import { Card } from './modules/card';
import { popupEditProfile } from './modules/popups/popupEditProfile';
import { popupEdit } from './modules/popups/popupEdit';
import checkInputs from './modules/validation/checkInputs';
import checkFormProfile from './modules/validation/checkFormProfile';


const placeList = document.querySelector(".places-list");
const buttonPlus = document.querySelector('.user-info__button');
const buttonEdit = document.querySelector('.user-info__edit');
const userName = document.querySelector('.user-info__name');
const userJob = document.querySelector('.user-info__job');
const avatar = document.querySelector('.user-info__photo');

const myId = "a8f785f65a89fd5aa5faf82c";

// Listener popups

buttonEdit.addEventListener('click', function(){
  popupEdit.open();
  checkInputs(popupEdit.popup.querySelector('.popup__form'));
});

buttonPlus.addEventListener('click', function(){
  popupAdd.open();
  checkInputs(popupAdd.popup.querySelector('.popup__form'));
});

avatar.addEventListener('click', function(){
  popupEditProfile.open();
  checkFormProfile(popupEditProfile.popup.querySelector('.popup__form'));
})

// Download info for start page (cards and infoProfile)

api.getInitialCards()
  .then((res) => {
    for(let i = 0; i < res.length; i++) {
      const {cardElement} = new Card(res[i].name, res[i].link, res[i].likes.length, res[i]._id);
      placeList.appendChild(cardElement);
      if(res[i].owner._id !== myId) {
        cardElement.querySelector('.place-card__delete-icon').style.display="none";
      }
      if(res[i].likes.some(function(human) {
        return human._id === myId
      })) {
        cardElement.querySelector('.place-card__like-icon').classList.add('place-card__like-icon_liked');
      }
    }
  })
  .catch(err => {
    console.error(err);
  });

api.getInfoAboutMe()
  .then((res) => {
    console.log(res);
    userName.textContent = res.name;
    userJob.textContent = res.about;
    avatar.style.backgroundImage = `url("${res.avatar}")`;
  })  
  .catch(err => {
    console.error(err);
  });