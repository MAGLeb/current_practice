import { Card } from './card';

const initialCards = [];
const placeList = document.querySelector(".places-list");

class CardList {
    constructor(container, cardArray) {
      this.container = container;
      this.cardArray = cardArray;
      this.render();
      
    }
  
    addCard(name, link, likes, cardId) {
      const {cardElement} = new Card(name, link, likes, cardId);
      this.container.appendChild(cardElement);
    }
  
    render() {
      for(let i = 0; i < this.cardArray.length; i++) {
        this.addCard(this.cardArray[i].name, this.cardArray[i].link, this.cardArray[i].likes.length);
      }
    }
    
};

export const cardList = new CardList(placeList, initialCards);