from tkinter import *
from tkinter import messagebox
from PIL import Image, ImageTk
from hotel import open_hotel
import config


class LoginPage:
    def __init__(self, root):
        self.root = root
        self.root.title("Inkeeper's Suite Login")
        self.root.geometry("1550x800+0+0")

        # ===== Background Image =====
        img = Image.open("main loby.jpeg")
        img = img.resize((1550,800), Image.Resampling.LANCZOS)
        self.bg = ImageTk.PhotoImage(img)

        bg_label = Label(self.root, image=self.bg)
        bg_label.place(x=0,y=0,width=1550,height=800)


        # ===== Top Title =====
        title = Label(
            self.root,
            text="WELCOME TO INKEEPER'S SUITE",
            font=("Georgia",38,"bold"),
            bg="black",
            fg="light gray"
        )
        title.place(x=0,y=50,width=1550,height=60)



        # ===== Center Login Frame (smaller and cleaner) =====
        login_frame = Frame(
            self.root,
            bg="light grey",
            bd=6,
            relief=RIDGE
        )
        login_frame.place(x=610,y=230,width=340,height=360)



        heading = Label(
            login_frame,
            text="Login",
            font=("Georgia",24,"bold"),
            bg="light grey",
            fg="black"
        )
        heading.pack(pady=(18,20))



        # Username Label
        user_lbl = Label(
            login_frame,
            text="Username",
            font=("times new roman",15,"bold"),
            bg="light grey",
            anchor="w"
        )
        user_lbl.pack(fill="x",padx=40)

        self.user_entry = Entry(
            login_frame,
            font=("times new roman",15),
            bd=2,
            relief=SOLID
        )
        self.user_entry.pack(padx=40,pady=(6,18),fill="x")



        # Password Label
        pass_lbl = Label(
            login_frame,
            text="Password",
            font=("times new roman",15,"bold"),
            bg="light grey",
            anchor="w"
        )
        pass_lbl.pack(fill="x",padx=40)

        self.pass_entry = Entry(
            login_frame,
            show="*",
            font=("times new roman",15),
            bd=2,
            relief=SOLID
        )
        self.pass_entry.pack(padx=40,pady=(6,22),fill="x")



        # Bigger Login Button
        login_btn = Button(
            login_frame,
            text="LOGIN",
            command=self.login,
            font=("Calibri",15,"bold"),
            bg="black",
            fg="light gray",
            cursor="hand2",
            width=18,
            height=1
        )
        login_btn.pack()



    def login(self):

        username = self.user_entry.get()
        password = self.pass_entry.get()
        if username == config.ADMIN_USERNAME and password == config.ADMIN_PASSWORD:
            messagebox.showinfo("Success","Login Successful")
            self.root.destroy()
            open_hotel()

        else:
            messagebox.showerror("Error","Invalid Username or Password")



if __name__=="__main__":
    root = Tk()
    obj = LoginPage(root)
    root.mainloop()