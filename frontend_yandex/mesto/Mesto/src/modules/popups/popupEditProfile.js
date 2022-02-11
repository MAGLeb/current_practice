import { Popup } from './popup';
import { api } from '../api/api';

const avatar = document.querySelector('.user-info__photo');

class PopupEditProfile extends Popup {
    constructor(popup) {
      super(popup);
    }
  
    submit() {
      event.preventDefault();
      api.loadAvatar(document.forms.profile.link.value)
        .then(() => {
          avatar.style.backgroundImage=`url("${document.forms.profile.link.value}")`;
          super.close();
          document.forms.profile.link.value = "";
        })
        .catch(err => console.log(err));
    }
}

export const popupEditProfile = new PopupEditProfile(document.querySelector('.popup.popup-edit-profile'));