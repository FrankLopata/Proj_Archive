from tkinter import *
DEFAULT_FONT = ('Helvetica', 20)
class Gui:

    def __init__(self):
        self._window = Tk()
        self._window.geometry("600x600+10+20")
        self._enter = Button(master = self._window, text = 'Enter', font = DEFAULT_FONT)
        self._enter.pack(side = BOTTOM)
        self._enter.anchor(SE)
        self._entry=Entry(self._window, text="", bd=5)
        self._entry.pack(side = BOTTOM,fill=X)
        self._enter.anchor(SE)
        self._canvas = Canvas(master = self._window, background = '#600000')
        self._listbox = Listbox(master = self._window, width = 50, height = 50,bg="white",activestyle="dotbox",fg="blue" )
        self._listbox.pack()
    def run(self):
        self._window.mainloop()
if __name__ == '__main__':
    Gui().run()