import { api } from './api/api';

const approximate = document.querySelector('.approximate'); 
const approximateImage = document.querySelector('.approximate-image__image');
const approximateClose = document.querySelector('.approximate__close');

export class Card {
    constructor (name, link, likes, cardId) {
      this.cardElement = this.create(name, link, likes, cardId);
      
      this.approximate = this.onApproximateClickHandler.bind(this);
      this.onLikeClickHandler = this.onLikeClickHandler.bind(this);
      this.onRemoveClickHandler = this.onRemoveClickHandler.bind(this);
  
      this.cardElement.querySelector('.place-card__delete-icon').addEventListener('click', this.onRemoveClickHandler);
      this.cardElement.querySelector('.place-card__image').addEventListener('click', this.onApproximateClickHandler);
      this.cardElement.querySelector('.place-card__like-icon').addEventListener('click', this.onLikeClickHandler);
    }
  
    onApproximateClickHandler(event) {
      if (event.target.classList.contains('place-card__image')) {
        approximateImage.src = event.target.style.backgroundImage.slice(5, -2);
        approximate.classList.add('approximate_is-opened');
      }
    }
  
    create(name, link, likes, cardId) {
      const placeCard = document.createElement('div');
      const placeCardIcon = document.createElement('button');
      const cardImage = document.createElement('div');
      const placeCardDescription = document.createElement('div');
      const placeCardName = document.createElement('h3');
      const containerColumn = document.createElement('div');
      const likeCount = document.createElement('p');
      const button = document.createElement('button');
  
      containerColumn.classList.add('column');
      likeCount.classList.add('place-card__like-count');
      placeCard.classList.add('place-card');
      cardImage.classList.add('place-card__image');
      button.classList.add('place-card__delete-icon');
      placeCardName.classList.add('place-card__name');
      placeCardIcon.classList.add('place-card__like-icon');
      placeCardDescription.classList.add('place-card__description');
      
      cardImage.setAttribute('style', `background-image: url(${link})`);
      placeCardName.textContent = name;
      likeCount.textContent = likes;
      button.setAttribute("cardId", cardId);
      placeCardIcon.setAttribute("cardId", cardId);
      
      containerColumn.appendChild(placeCardIcon);
      containerColumn.appendChild(likeCount);
      placeCardDescription.appendChild(placeCardName);
      placeCardDescription.appendChild(containerColumn);
      cardImage.appendChild(button);
      placeCard.appendChild(cardImage);
      placeCard.appendChild(placeCardDescription);
  
      return placeCard;
    }
  
    onLikeClickHandler(event) {
      if(event.target.classList.contains('place-card__like-icon_liked')) {
        api.disLike(event.target.getAttribute("cardId"))
          .then(() => {
            event.target.parentNode.querySelector('p').textContent--;
            event.target.classList.toggle('place-card__like-icon_liked');
          })
      } else {    
        api.putLike(event.target.getAttribute("cardId"))
          .then(() => {
            event.target.parentNode.querySelector('p').textContent++;
            event.target.classList.toggle('place-card__like-icon_liked');
          })
      }
    }
  
    onRemoveClickHandler(event) {
      if(window.confirm("Do you really want to delete the card?")) {
        api.deleteCard(event.target.getAttribute("cardId"))
          .then(() =>{
            this.cardElement.parentNode.removeChild(this.cardElement);
          })
          .catch(err => console.log(err));
      }
    }
}

approximateClose.addEventListener('click', () => {
  approximate.classList.remove('approximate_is-opened');  
});