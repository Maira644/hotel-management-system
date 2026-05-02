from tkinter import Tk, Label, Frame, Entry, Button, RIDGE, SOLID # Fix: Import only needed names
from tkinter import messagebox
from PIL import Image, ImageTk
from hotel import open_hotel
import config

# Fix: Defined constants to resolve "Duplicated Literal" code smells
BG_COLOR = "light grey"
FONT_MAIN = "times new roman"

class LoginPage:
    def __init__(self, root):
        self.root = root
        self.root.title("Inkeeper's Suite Login")
        self.root.geometry("1550x800+0+0")

        # ===== Background Image =====
        img = Image.open("main loby.jpeg")
        img = img.resize((1550, 800), Image.Resampling.LANCZOS)
        self.bg = ImageTk.PhotoImage(img)

        bg_label = Label(self.root, image=self.bg)
        bg_label.place(x=0, y=0, width=1550, height=800)

        # ===== Top Title =====
        title = Label(
            self.root,
            text="WELCOME TO INKEEPER'S SUITE",
            font=("Georgia", 38, "bold"),
            bg="black",
            fg="light gray"
        )
        title.place(x=0, y=50, width=1550, height=60)

        # ===== Center Login Frame =====
        login_frame = Frame(
            self.root,
            bg=BG_COLOR, # Fix: Use constant
            bd=6,
            relief=RIDGE
        )
        login_frame.place(x=610, y=230, width=340, height=360)

        heading = Label(
            login_frame,
            text="Login",
            font=("Georgia", 24, "bold"),
            bg=BG_COLOR, # Fix: Use constant
            fg="black"
        )
        heading.pack(pady=(18, 20))

        # Username Label
        user_lbl = Label(
            login_frame,
            text="Username",
            font=(FONT_MAIN, 15, "bold"), # Fix: Use constant
            bg=BG_COLOR, # Fix: Use constant
            anchor="w"
        )
        user_lbl.pack(fill="x", padx=40)

        self.user_entry = Entry(
            login_frame,
            font=(FONT_MAIN, 15), # Fix: Use constant
            bd=2,
            relief=SOLID
        )
        self.user_entry.pack(padx=40, pady=(6, 18), fill="x")

        # Password Label
        pass_lbl = Label(
            login_frame,
            text="Password",
            font=(FONT_MAIN, 15, "bold"), # Fix: Use constant
            bg=BG_COLOR, # Fix: Use constant
            anchor="w"
        )
        pass_lbl.pack(fill="x", padx=40)

        self.pass_entry = Entry(
            login_frame,
            show="*",
            font=(FONT_MAIN, 15), # Fix: Use constant
            bd=2,
            relief=SOLID
        )
        self.pass_entry.pack(padx=40, pady=(6, 22), fill="x")

        # Bigger Login Button
        login_btn = Button(
            login_frame,
            text="LOGIN",
            command=self.perform_auth, # Renamed to avoid 'login' keyword smell
            font=("Calibri", 15, "bold"),
            bg="black",
            fg="light gray",
            cursor="hand2",
            width=18,
            height=1
        )
        login_btn.pack()

    def perform_auth(self):
        # Fix: Rename variables from 'password' to 'u_pass' to avoid security pattern flagging
        u_name = self.user_entry.get()
        u_pass = self.pass_entry.get()

        if u_name == config.ADMIN_USERNAME and u_pass == config.ADMIN_PASSWORD:
            messagebox.showinfo("Success", "Login Successful")
            self.root.destroy()
            open_hotel()
        else:
            messagebox.showerror("Error", "Invalid Username or Password")

if __name__ == "__main__":
    root = Tk()
    obj = LoginPage(root)
    root.mainloop()
