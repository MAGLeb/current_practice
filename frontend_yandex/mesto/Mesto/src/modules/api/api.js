class Api {
    constructor(options) {
      if(options.baseUrl.endsWith('/')) {
        options.baseUrl = options.baseUrl.substring(0, url.length - 2);
      }
      this.options = options;
      this.url = options.baseUrl;
      this.authorization = options.headers.authorization;
    }
  
    getInitialCards(){
      return fetch(`${this.url}/cards`, {
        headers: {
          authorization: this.authorization,
        }
      }) 
        .then(res => {
          if (res.ok) {
            return res.json();
          }
          return Promise.reject(`Ошибка: ${res.status}`);
        })
    }
  
    getInfoAboutMe(){
      return fetch(`${this.url}/users/me`, {
        method: 'GET',
        headers: {
          authorization: this.authorization,
        },
      })
      .then(res => {
        if (res.ok) {
          return res.json();
        }
        return Promise.reject(`Ошибка: ${res.status}`);
      })
    }
  
    editProfile(name, job){
      return fetch(`${this.url}/users/me`, {
        method: 'PATCH',
        headers: {
            authorization: this.authorization,
            'Content-Type': 'application/json'
        },
        body: JSON.stringify({
          name: name,
          about: job
        }) 
      })
        .then(res => {
          if (res.ok) {
            return res.json();
          }
          return Promise.reject(`Ошибка: ${res.status}`);
        })
    }
  
    addNewCard(name, link){
      return fetch(`${this.url}/cards`, {
        method: 'POST',
        headers: {
          authorization: this.authorization,
          'Content-Type': 'application/json'
        },
        body: JSON.stringify({
          name: name,
          link: link
        })
      })
        .then(res => {
          if (res.ok) {
            return res.json();
          }
          return Promise.reject(`Ошибка: ${res.status}`);
        })
    }
  
    deleteCard(cardId){
      return fetch(`${this.url}/cards/${cardId}`, {
        method: 'DELETE',
        headers: {
          authorization: this.authorization
        }
      })
      .then(res => {
        if (res.ok) {
          return res.json();
        }
        return Promise.reject(`Ошибка: ${res.status}`);
      })
    }
  
    putLike(cardId) {
      return fetch(`${this.url}/cards/like/${cardId}`, {
        method: 'PUT',
        headers: {
          authorization: this.authorization
        }
      })
      .then(res => {
        if (res.ok) {
          return res.json();
        }
        return Promise.reject(`Ошибка: ${res.status}`);
      })
    }
  
    disLike(cardId) {
      return fetch(`${this.url}/cards/like/${cardId}`, {
        method: 'DELETE',
        headers: {
          authorization: this.authorization
        }
      })
      .then(res => {
        if (res.ok) {
          return res.json();
        }
        return Promise.reject(`Ошибка: ${res.status}`);
      })
    }
  
    loadAvatar(avatar) {
      return fetch(`${this.url}/users/me/avatar`, {
        method: 'PATCH',
        headers: {
          authorization: this.authorization,
          'Content-Type': 'application/json'
        },
        body: JSON.stringify ({
          avatar: avatar
        }),
      })
      .then(res => {
        if (res.ok) {
          return res.json();
        }
        return Promise.reject(`Ошибка: ${res.status}`);
      })
    }
};

export const api = new Api({
    baseUrl: window.location.href.indexOf('localhost') > -1 ? "http://praktikum.tk/cohort1" : "https://praktikum.tk/cohort1",
    headers: {
        authorization: 'c8bcfd30-1fb2-4b36-9349-119fc6b4bb78',
        'Content-Type': 'application/json'
    }
})