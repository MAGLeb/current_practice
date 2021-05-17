from tkinter import *
from tkinter import ttk
from tkinter import font

import random
import time


class TextController:
    def __init__(self):
        self.actions = [
            "Eye movement: up and down.",
            "Diagonal eye movement.",
            "Draw vertical and horizontal spirals with your eyes.",
            "Close your eyes tightly.",
            "Draw infinity with your eyes.",
            "Reducing the eyes to the nose.",
            "Focus on a distant object.",
            "Grab a drink of water.",
            "Blink your eyes."
        ]
        self.visited = []
        self.size = len(self.actions)

        random.shuffle(self.actions)

    def get_text(self) -> str:
        for i in range(self.size):
            if i not in self.visited:
                self.visited.append(i)

                if len(self.visited) == self.size:
                    self.visited = []
                    random.shuffle(self.actions)

                return self.actions[i]


class RenderTimer:
    def __init__(self, time_action: int):
        self.root = Tk(className='TimerApplication')
        self.text_controller = TextController()
        self.label = StringVar()
        self.time_action = time_action
        self.curr_time_action = time_action
        self.text = None

        self.root.attributes("-fullscreen", True)
        self.root.wait_visibility(self.root)
        self.root.wm_attributes('-alpha', 0.7)
        self.root.configure(background='black')
        self.root.bind("<Escape>", self.handle_quit)
        self.set_label()
        self.root.after(1000, self.render_timer)
        self.root.mainloop()

    def handle_quit(self, *args):
        self.root.destroy()

    def render_timer(self):
        self.curr_time_action -= 1
        self.label.set(f"{self.curr_time_action} {self.text}")

        if self.curr_time_action == 0:
            self.curr_time_action = self.time_action
            self.handle_quit()
        else:
            self.root.after(1000, self.render_timer)

    def set_label(self):
        self.text = self.text_controller.get_text()
        self.label.set(f"{self.time_action} {self.text}")
        fnt = font.Font(family='Helvetica', size=48, weight='bold')
        label = ttk.Label(self.root, textvariable=self.label, font=fnt, foreground="white", background="black")
        label.place(relx=0.5, rely=0.5, anchor=CENTER)


class ApplicationDesktop:
    def __init__(self, gap_time: int = 60, action_time: int = 24):
        """
        Vacation reminder app.

        :param gap_time: every 'gap_time' minutes show notification
        :param action_time: time to do action
        """

        time.sleep(60 * gap_time)
        while True:
            RenderTimer(action_time)
            time.sleep(60 * gap_time + action_time)


ApplicationDesktop(gap_time=1, action_time=15)
