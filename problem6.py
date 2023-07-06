from tkinter import E


class Freeway:
    def __init__(self) -> None:
        self._display = (1,1)
        #Default Display size ^
        self._leftchicken = (0,0)
        self._rightchicken = (1,0)
        self._joystick= (0,0)

    def _move_lchicken_up(self)->None:
        self._leftchicken = (self._leftchicken[0], self._leftchicken[1]+0.05)
    def _check_joystick_pos(self)->None:
        #This function will always run as long as game is on
        if(self._joystick==(0,1)):
            self._move_lchicken_up()

    def get_lchick_loc(self)->None:
        return self._leftchicken

    def get_rchick_loc(self)->None:
        return self._rightchicken


