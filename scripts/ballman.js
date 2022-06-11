`
1- if player is not playing and if energy enough
    2- press play button
    3- if train button text == "Train now"
        - train
    else
        - press match button
4- else
    5- change player

if every player is not ready
create timer for 5 minutes
`

async function trainPlayer() {
    const playButton = document.getElementsByTagName('button')[2];
    playButton.click();
    await new Promise(resolve => setTimeout(resolve, 5000));

    const trainingBlock = document.getElementsByClassName('gFOKlF')[0];
    const trainButton = trainingBlock.getElementsByClassName('kQBBYJ')[0];

    const matchBlock = document.getElementsByClassName('hJBYJl')[0];
    const matchButton = matchBlock.getElementsByClassName('gSmTBV')[0];

    if (trainButton.textContent == "Train now") {
        trainButton.click();
    } else {
        matchButton.click();
    }
    await new Promise(resolve => setTimeout(resolve, 15000));
    goHomePage();
    await new Promise(resolve => setTimeout(resolve, 15000));
}

function goHomePage() {
    const background = document.getElementsByClassName('hBxvlc');

    if(background.length > 0) {
        const changeButton = document.getElementsByClassName('chMlbY')[0];
        changeButton.click();
    }

    const header = document.getElementsByClassName('cBVDSE');
    header[0].children[0].click();
}

async function changePlayerPage (players) {
    goHomePage();
    await new Promise(resolve => setTimeout(resolve, 15000));

    const changeButton = document.getElementsByClassName('chMlbY')[0];
    changeButton.click();
    await new Promise(resolve => setTimeout(resolve, 15000));

    let answer = false;
    const divPlayersCards = document.getElementsByClassName('bhNyGt')[0].children;
    
    for(let i = 0; i < divPlayersCards.length; i++) {
        const playerName = divPlayersCards[i].getElementsByClassName('jbJXOi')[0].textContent;

        if (i == divPlayersCards.length - 1 && players.has(playerName)) {
            divPlayersCards[i].getElementsByClassName('dzATUs')[0].click();
            break;
        }
        else if (players.has(playerName)) {
            continue;
        } else {
            divPlayersCards[i].getElementsByClassName('dzATUs')[0].click();
            players.add(playerName);
            answer = true;
            break;
        }
    }

    return answer;
}

async function main() {
    while(true) {
        try {
                
            let cycle = true;
            let counter = 0;
            let players = new Set();

            while(cycle) {
                const liveButton = document.getElementsByClassName('biPmv')[0];
                const energyBar = document.getElementById('energy_bar').children[9];
                const energyBarLastFieldClassName = energyBar.className['animVal'].split(' ')[1];

                if (!liveButton && energyBarLastFieldClassName == 'iksHHD') {
                    await trainPlayer();
                }

                cycle = await changePlayerPage(players);

                if(!cycle) {
                    players = new Set();
                    cycle = true;
                    await new Promise(resolve => setTimeout(resolve, 15000));
                } else {
                    await new Promise(resolve => setTimeout(resolve, 5000));
                }
                counter++;
                console.log(counter);
            }
        }
        catch(error) {
            console.log(error);
            goHomePage();
            await new Promise(resolve => setTimeout(resolve, 180000));
        }
    };
}

main();

main();

