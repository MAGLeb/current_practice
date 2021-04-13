import curses
import random

FIELD_WIDTH = 7
FIELD_HEIGHT = 6
MAX_FIELDS_TO_WIN = 4
ALL_PLAYERS = ["X", "O"]


class MainGame:
    def __init__(self):
        self.fields = [["_" for _ in range(FIELD_WIDTH)] for _ in range(FIELD_HEIGHT)]
        self.fields_status = [[[0, 0] for _ in range(FIELD_WIDTH)] for _ in range(FIELD_HEIGHT)]
        self.who_turn = None

        self.screen = curses.initscr()
        self.screen.clear()
        self._who_first_turn()
        self._render_field()

    def start(self):
        """
        Infinite loop until someone wins.
        """
        while True:
            # character encodings for digits are all in order from 48
            column = self.screen.getch() - 48

            if 0 <= column < FIELD_WIDTH:
                if self.fill_field_and_check_for_over(column):
                    break
            else:
                print(f"'column: {column}' should be from range(0-{FIELD_WIDTH - 1})")

    def _who_first_turn(self):
        """
        Random choose player to start.
        """
        random_player = random.randint(0, len(ALL_PLAYERS) - 1)
        self.who_turn = ALL_PLAYERS[random_player]

    def fill_field_and_check_for_over(self, column: int) -> bool:
        """
        Fill field and check for over game. Loop check for empty slot in column.
        :param column: number column to fill.
        :return: is game over?
        """
        for i in range(FIELD_HEIGHT - 1, -2, -1):
            if i == -1:
                print("This column is full! Choose another one.")
                break

            if "_" in self.fields[i][column]:
                self.fields[i][column] = self.who_turn

                if self._check_for_win(i, column):
                    self._render_field()
                    self.screen.clear()
                    self.screen.addstr(10, 10, f"WIN {self.who_turn}")
                    self.screen.addstr(11, 10, "Press any key to close console")

                    if self.screen.getch():
                        curses.endwin()
                        return True

                self._change_turn()
                self._render_field()
                break

        return False

    def _change_turn(self):
        """
        Passes the move to the next one.
        """
        curr_index = ALL_PLAYERS.index(self.who_turn)
        curr_index += 1

        if curr_index >= len(ALL_PLAYERS):
            curr_index = 0

        self.who_turn = ALL_PLAYERS[curr_index]

    def _check_for_win(self, index_height, index_width) -> bool:
        """
        This function checks whether the game is over or not. In order not to completely go through the entire matrix
        looking for a sequence of "MAX_FIELDS_TO_WIN = 4" identical characters, we simplify the asymptotic complexity
        and use additional memory and dynamic programming. By creating an array for each element and store in it
        the state [number of vertically identical characters, number of horizontally identical characters].
        :param index_height: vertical index of the element.
        :param index_width: horizontal index of the element.
        :return: did someone win?
        """
        vertical = 1
        horizontal = 1

        # the three checks below calculate values for the state matrix of a current element
        if 0 < index_height < FIELD_HEIGHT - 1:
            if self.fields[index_height + 1][index_width] == self.who_turn:
                vertical += self.fields_status[index_height + 1][index_width][0]
        if 0 < index_width:
            if self.fields[index_height][index_width - 1] == self.who_turn:
                horizontal += self.fields_status[index_height][index_width - 1][1]
        if index_width < FIELD_WIDTH - 1:
            if self.fields[index_height][index_width + 1] == self.who_turn:
                horizontal += self.fields_status[index_height][index_width + 1][1]

        # the two checks below are required to update the state of elements on the edges
        if 0 < index_width:
            if self.fields[index_height][index_width - 1] == self.who_turn:
                self.fields_status[index_height][index_width - 1][1] = horizontal
        if index_width < FIELD_WIDTH - 1:
            if self.fields[index_height][index_width + 1] == self.who_turn:
                self.fields_status[index_height][index_width + 1][1] = horizontal

        self.fields_status[index_height][index_width] = [vertical, horizontal]

        if vertical == MAX_FIELDS_TO_WIN or horizontal == MAX_FIELDS_TO_WIN:
            return True
        else:
            return False

    def _render_field(self):
        """
        Render fields in console.
        """
        self.screen.addstr(0, 15, f"TURN {self.who_turn}")

        shift = 1
        for j in range(FIELD_WIDTH):
            self.screen.addstr(2, j + 10 + shift, str(j) + " ")
            shift += 1

        for i in range(FIELD_HEIGHT):
            shift = 1
            for j in range(FIELD_WIDTH):
                self.screen.addstr(i + 3, j + 10 + shift, str(self.fields[i][j]) + " ")
                shift += len(str(self.fields[i][j]))

        self.screen.refresh()


def main():
    game = MainGame()
    game.start()


if __name__ == '__main__':
    main()
