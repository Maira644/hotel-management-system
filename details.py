import tkinter as tk
from tkinter import ttk
from tkinter import messagebox
from PIL import Image, ImageTk
import mysql.connector
import config

class RoomBookingDetails:
    def __init__(self, root):
        self.root = root
        self.root.title("Room Booking Details")
        self.root.geometry("1295x550+230+220")

        # ====================title======================
        lbl_title = tk.Label(self.root, text="Room Booking Details", 
                             font=("times new roman", 18, "bold"), 
                             bg="black", fg="gray", bd=4, relief=tk.RIDGE)
        lbl_title.place(x=0, y=0, width=1295, height=50)

        # ====================logo======================
        img2 = Image.open("logo.jpeg")
        img2 = img2.resize((100, 40), Image.Resampling.LANCZOS)
        self.photoimg2 = ImageTk.PhotoImage(img2)

        lblimg = tk.Label(self.root, image=self.photoimg2, bd=0, relief=tk.RIDGE)
        lblimg.place(x=5, y=2, width=100, height=48)

        # =================label frame====================
        labelframeleft = tk.LabelFrame(self.root, bd=2, relief=tk.RIDGE, text="New Room Add", 
                                       font=("times new roman", 12, "bold"), padx=2)
        labelframeleft.place(x=5, y=50, width=540, height=350)

        # =================labels and entries==============
        # Floor
        lbl_floor = tk.Label(labelframeleft, text="Floor", font=("arial", 12, "bold"), 
                             padx=2, pady=6)
        lbl_floor.grid(row=0, column=0, sticky=tk.W, padx=20)

        self.var_floor = tk.StringVar()
        entry_floor = ttk.Entry(labelframeleft, textvariable=self.var_floor, 
                                font=("arial", 13, "bold"), width=20)
        entry_floor.grid(row=0, column=1, sticky=tk.W)
        
        # Room Number
        lbl_RoomNo = tk.Label(labelframeleft, text="Room Number", font=("arial", 12, "bold"), 
                              padx=2, pady=6)
        lbl_RoomNo.grid(row=1, column=0, sticky=tk.W, padx=20)

        self.var_RoomNo = tk.StringVar()
        entry_RoomNo = ttk.Entry(labelframeleft, textvariable=self.var_RoomNo, 
                                 font=("arial", 13, "bold"), width=20)
        entry_RoomNo.grid(row=1, column=1, sticky=tk.W)

        # Room Type
        lbl_RoomType = tk.Label(labelframeleft, text="Room Type", font=("arial", 12, "bold"), 
                                padx=2, pady=6)
        lbl_RoomType.grid(row=2, column=0, sticky=tk.W, padx=20)

        self.var_RoomType = tk.StringVar()
        entry_RoomType = ttk.Entry(labelframeleft, textvariable=self.var_RoomType, 
                                   font=("arial", 13, "bold"), width=20)
        entry_RoomType.grid(row=2, column=1, sticky=tk.W)

        # ================button====================
        btn_frame = tk.Frame(labelframeleft, bd=2, relief=tk.RIDGE)
        btn_frame.place(x=0, y=200, width=412, height=38)

        btnAdd = tk.Button(btn_frame, text="Add", command=self.add_data, 
                           font=("arial", 13, "bold"), bg="black", fg="gray", width=9)
        btnAdd.grid(row=0, column=0, padx=1)

        btnUpdate = tk.Button(btn_frame, text="Update", command=self.update, 
                              font=("arial", 13, "bold"), bg="black", fg="gray", width=9)
        btnUpdate.grid(row=0, column=1, padx=1)

        btnDelete = tk.Button(btn_frame, text="Delete", command=self.mDelete, 
                              font=("arial", 13, "bold"), bg="black", fg="gray", width=9)
        btnDelete.grid(row=0, column=2, padx=1)

        btnReset = tk.Button(btn_frame, text="Reset", command=self.reset_data, 
                             font=("arial", 13, "bold"), bg="black", fg="gray", width=9)
        btnReset.grid(row=0, column=3, padx=1)

        # ==============table frame search system====================
        Table_Frame = tk.LabelFrame(self.root, bd=2, relief=tk.RIDGE, text="Show Room Details", 
                                    font=("arial", 12, "bold"), padx=2)
        Table_Frame.place(x=600, y=55, width=600, height=350)

        scroll_x = ttk.Scrollbar(Table_Frame, orient=tk.HORIZONTAL)
        scroll_y = ttk.Scrollbar(Table_Frame, orient=tk.VERTICAL)

        self.Room_Table = ttk.Treeview(Table_Frame, column=("floor", "roomno", "roomtype"), 
                                       xscrollcommand=scroll_x.set, yscrollcommand=scroll_y.set)
        scroll_x.pack(side=tk.BOTTOM, fill=tk.X)
        scroll_y.pack(side=tk.RIGHT, fill=tk.Y)

        scroll_x.config(command=self.Room_Table.xview)
        scroll_y.config(command=self.Room_Table.yview)

        self.Room_Table.heading("floor", text="Floor")
        self.Room_Table.heading("roomno", text="Room No")
        self.Room_Table.heading("roomtype", text="Room Type")
        
        self.Room_Table["show"] = "headings"

        self.Room_Table.column("floor", width=100)
        self.Room_Table.column("roomno", width=100)
        self.Room_Table.column("roomtype", width=100)
        
        self.Room_Table.pack(fill=tk.BOTH, expand=1)
        self.Room_Table.bind("<ButtonRelease-1>", self.get_cursor)
        self.fetch_data()

    # Add data
    def add_data(self):
        if self.var_floor.get() == "" or self.var_RoomType.get() == "":
            messagebox.showerror("Error", "All fields are required", parent=self.root)
        else:
            try:
                conn = mysql.connector.connect(host="localhost", username="root", 
                                              password=config.DB_PASSWORD, database="suite")
                my_cursor = conn.cursor()
                my_cursor.execute("INSERT INTO details VALUES(%s,%s,%s)", (
                    self.var_floor.get(),
                    self.var_RoomNo.get(),
                    self.var_RoomType.get(),
                ))
                conn.commit()
                self.fetch_data()
                conn.close()
                messagebox.showinfo("Success", "New Room Added Successfully", parent=self.root)
            except Exception as es:
                messagebox.showwarning("warning", f"Something Went Wrong:{str(es)}", parent=self.root)

    # Fetch data 
    def fetch_data(self):
        conn = mysql.connector.connect(host="localhost", username="root", 
                                      password=config.DB_PASSWORD, database="suite")
        my_cursor = conn.cursor()
        my_cursor.execute("select * from details")
        rows = my_cursor.fetchall()
        if len(rows) != 0:
            self.Room_Table.delete(*self.Room_Table.get_children())
            for i in rows:
                self.Room_Table.insert("", tk.END, values=i)
            conn.commit()
        conn.close()

    # Get cursor
    def get_cursor(self, event=""):
        cursor_row = self.Room_Table.focus()
        content = self.Room_Table.item(cursor_row)
        row = content["values"]
        if row:
            self.var_floor.set(row[0])
            self.var_RoomNo.set(row[1])
            self.var_RoomType.set(row[2])

    # Update function   
    def update(self):
        if self.var_floor.get() == "":
            messagebox.showerror("Error", "Please Enter Floor Number", parent=self.root)
        else:
            conn = mysql.connector.connect(host="localhost", username="root", 
                                          password=config.DB_PASSWORD, database="suite")
            my_cursor = conn.cursor()
            my_cursor.execute("Update details set Floor=%s,RoomType=%s where RoomNo=%s", (
                self.var_floor.get(),
                self.var_RoomType.get(),
                self.var_RoomNo.get(),
            ))
            conn.commit()
            self.fetch_data()
            conn.close()
            messagebox.showinfo("Update", "New Room details has been updated successfully", parent=self.root)

    def mDelete(self):
        m_delete = messagebox.askyesno("Inkeeper's Suite", "Do you want to delete this Room Details", parent=self.root)
        if m_delete > 0:
            conn = mysql.connector.connect(host="localhost", username="root", 
                                          password=config.DB_PASSWORD, database="suite")
            my_cursor = conn.cursor()
            query = "delete from details where RoomNo=%s"
            value = (self.var_RoomNo.get(),)
            my_cursor.execute(query, value)
            conn.commit()
            self.fetch_data()
            conn.close()

    def reset_data(self):
        self.var_floor.set("")
        self.var_RoomNo.set("")
        self.var_RoomType.set("")

if __name__ == "__main__":
    root = tk.Tk()
    obj = RoomBookingDetails(root)
    root.mainloop()
