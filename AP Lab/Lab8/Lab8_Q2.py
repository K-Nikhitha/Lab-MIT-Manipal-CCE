import tkinter as tk
from unittest import result
field_text = ""
def add_to_field(sth):
    global field_text
    field_text = field_text  + str(sth)
    field.delete("1.0","end")
    field.insert("1.0",field_text)

def calculate():
    global field_text
    result = str(eval(field_text))
    field.delete("1.0","end")
    field.insert("1.0",result)


def clear():
    global field_text
    field_text = ""
    field.delete("1.0","end")

window = tk.Tk()
window.geometry('200x200')
field = tk.Text(window,height=2,width=21)
field.grid(row=1,column=1,columnspan=4)

button_1 = tk.Button(window,text="1",command=lambda:add_to_field(1))
button_1.grid(row=4,column=1)
button_2 = tk.Button(window,text="2",command=lambda:add_to_field(2))
button_2.grid(row=4,column=2)
button_3 = tk.Button(window,text="3",command=lambda:add_to_field(3))
button_3.grid(row=4,column=3)
button_4 = tk.Button(window,text="4",command=lambda:add_to_field(4))
button_4.grid(row=3,column=1)
button_5 = tk.Button(window,text="5",command=lambda:add_to_field(5))
button_5.grid(row=3,column=2)
button_6 = tk.Button(window,text="6",command=lambda:add_to_field(6))
button_6.grid(row=3,column=3)
button_7 = tk.Button(window,text="7",command=lambda:add_to_field(7))
button_7.grid(row=2,column=1)
button_8 = tk.Button(window,text="8",command=lambda:add_to_field(8))
button_8.grid(row=2,column=2)
button_9 = tk.Button(window,text="9",command=lambda:add_to_field(9))
button_9.grid(row=2,column=3)
button_0 = tk.Button(window,text="0",command=lambda:add_to_field(0))
button_0.grid(row=5,column=1)
button_plus = tk.Button(window,text="+",command = lambda: add_to_field('+'))
button_plus.grid(row=4,column=4)
button_minus = tk.Button(window,text="-",command = lambda: add_to_field('-'))
button_minus.grid(row=5,column=4)
button_times = tk.Button(window,text="",command = lambda: add_to_field(''))
button_times.grid(row=3,column=4)
button_divison = tk.Button(window,text="/",command = lambda: add_to_field('/'))
button_divison.grid(row=2,column=4)
button_clear = tk.Button(window,text="clear",command = lambda: clear())
button_clear.grid(row=5,column=3)
button_decimal = tk.Button(window,text=".",command = lambda: add_to_field('.'))
button_decimal.grid(row=5,column=2)
button_open = tk.Button(window,text="(",command = lambda: add_to_field('('))
button_open.grid(row=6,column=1)
button_close = tk.Button(window,text=")",command = lambda: add_to_field(')'))
button_close.grid(row=6,column=2)
button_equal = tk.Button(window,text="=",command = lambda: calculate())
button_equal.grid(row=6,column=3)
window.mainloop()
