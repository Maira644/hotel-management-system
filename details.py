import tkinter as tk
from tkinter import ttk
from tkinter import messagebox
import mysql.connector
import config

class DetailsRoom:
    def __init__(self, root):
        self.root = root
        self.root.title("Room Management")
        self.root.geometry("1295x550+230+220")

        # ================== Variables ===================
        # Renamed var_RoomNo -> var_room_no and var_RoomType -> var_room_type
        self.var_room_no = tk.StringVar()
        self.var_room_type = tk.StringVar()

        # ==================== Title ======================
        lbl_title = tk.Label(self.root, text="ROOM DETAILS", 
                             font=("times new roman", 18, "bold"), 
                             bg="black", fg="gold", bd=4, relief=tk.RIDGE)
        lbl_title.place(x=0, y=0, width=1295, height=50)

        # ================= Label Frame Left ================
        labelframeleft = tk.LabelFrame(self.root, bd=2, relief=tk.RIDGE, 
                                       text="New Room Entry", 
                                       font=("times new roman", 12, "bold"), padx=2)
        labelframeleft.place(x=5, y=50, width=425, height=490)

        # ================= Labels and Entries ==============
        # Renamed lbl_RoomNo -> lbl_room_no and entry_RoomNo -> entry_room_no
        lbl_room_no = tk.Label(labelframeleft, text="Room No:", font=("arial", 12, "bold"), padx=2, pady=6)
        lbl_room_no.grid(row=0, column=0, sticky=tk.W)
        entry_room_no = ttk.Entry(labelframeleft, textvariable=self.var_room_no, font=("arial", 13, "bold"), width=20)
        entry_room_no.grid(row=0, column=1, sticky=tk.W)

        # Renamed lbl_RoomType -> lbl_room_type and entry_RoomType -> entry_room_type
        lbl_room_type = tk.Label(labelframeleft, text="Room Type:", font=("arial", 12, "bold"), padx=2, pady=6)
        lbl_room_type.grid(row=1, column=0, sticky=tk.W)
        entry_room_type = ttk.Entry(labelframeleft, textvariable=self.var_room_type, font=("arial", 13, "bold"), width=20)
        entry_room_type.grid(row=1, column=1, sticky=tk.W)

        # ================= Buttons Frame ===================
        btn_frame = tk.Frame(labelframeleft, bd=2, relief=tk.RIDGE)
        btn_frame.place(x=0, y=200, width=412, height=40)

        # Renamed btnAdd, btnUpdate, btnDelete, btnReset to snake_case
        btn_add = tk.Button(btn_frame, text="Add", command=self.add_data, width=9, 
                            font=("arial", 11, "bold"), bg="black", fg="gold")
        btn_add.grid(row=0, column=0)

        btn_update = tk.Button(btn_frame, text="Update", command=self.update, width=9, 
                               font=("arial", 11, "bold"), bg="black", fg="gold")
        btn_update.grid(row=0, column=1)

        btn_delete = tk.Button(btn_frame, text="Delete", command=self.m_delete, width=9, 
                               font=("arial", 11, "bold"), bg="black", fg="gold")
        btn_delete.grid(row=0, column=2)

        btn_reset = tk.Button(btn_frame, text="Reset", command=self.reset, width=9, 
                              font=("arial", 11, "bold"), bg="black", fg="gold")
        btn_reset.grid(row=0, column=3)

        # ================= Table Frame Right ================
        # Renamed Table_Frame -> table_frame
        table_frame = tk.LabelFrame(self.root, bd=2, relief=tk.RIDGE, 
                                    text="View Room Details", 
                                    font=("times new roman", 12, "bold"), padx=2)
        table_frame.place(x=435, y=50, width=850, height=490)

        # Renamed Room_Table -> room_table
        scroll_x = ttk.Scrollbar(table_frame, orient=tk.HORIZONTAL)
        scroll_y = ttk.Scrollbar(table_frame, orient=tk.VERTICAL)

        self.room_table = ttk.Treeview(table_frame, column=("roomno", "roomtype"), 
                                       xscrollcommand=scroll_x.set, yscrollcommand=scroll_y.set)
        
        scroll_x.pack(side=tk.BOTTOM, fill=tk.X)
        scroll_y.pack(side=tk.RIGHT, fill=tk.Y)
        scroll_x.config(command=self.room_table.xview)
        scroll_y.config(command=self.room_table.yview)

        self.room_table.heading("roomno", text="Room No")
        self.room_table.heading("roomtype", text="Room Type")
        self.room_table["show"] = "headings"

        self.room_table.pack(fill=tk.BOTH, expand=1)
        self.room_table.bind("<ButtonRelease-1>", self.get_cursor)
        self.fetch_data()

    # ================= Method Implementations =============
    def add_data(self):
        if self.var_room_no.get() == "" or self.var_room_type.get() == "":
            messagebox.showerror("Error", "All fields are required", parent=self.root)
        else:
            try:
                conn = mysql.connector.connect(host="localhost", user="root", 
                                              password=config.DB_PASSWORD, database="suite")
                my_cursor = conn.cursor()
                my_cursor.execute("insert into details values(%s,%s)", (
                    self.var_room_no.get(),
                    self.var_room_type.get()
                ))
                conn.commit()
                self.fetch_data()
                conn.close()
                messagebox.showinfo("Success", "Room added successfully", parent=self.root)
            except Exception as es:
                messagebox.showerror("Error", f"Something went wrong: {str(es)}", parent=self.root)

    def fetch_data(self):
        conn = mysql.connector.connect(host="localhost", user="root", 
                                      password=config.DB_PASSWORD, database="suite")
        my_cursor = conn.cursor()
        my_cursor.execute("select * from details")
        rows = my_cursor.fetchall()
        if len(rows) != 0:
            self.room_table.delete(*self.room_table.get_children())
            for i in rows:
                self.room_table.insert("", tk.END, values=i)
            conn.commit()
        conn.close()

    def get_cursor(self, event=""):
        cursor_row = self.room_table.focus()
        content = self.room_table.item(cursor_row)
        row = content["values"]
        if row:
            self.var_room_no.set(row[0])
            self.var_room_type.set(row[1])

    def update(self):
        if self.var_room_no.get() == "":
            messagebox.showerror("Error", "Please select a room to update", parent=self.root)
        else:
            conn = mysql.connector.connect(host="localhost", user="root", 
                                          password=config.DB_PASSWORD, database="suite")
            my_cursor = conn.cursor()
            my_cursor.execute("update details set RoomType=%s where RoomNo=%s", (
                self.var_room_type.get(),
                self.var_room_no.get()
            ))
            conn.commit()
            self.fetch_data()
            conn.close()
            messagebox.showinfo("Update", "Room details updated successfully", parent=self.root)

    def m_delete(self):
        m_delete = messagebox.askyesno("Room Management", "Do you want to delete this room?", parent=self.root)
        if m_delete > 0:
            conn = mysql.connector.connect(host="localhost", user="root", 
                                          password=config.DB_PASSWORD, database="suite")
            my_cursor = conn.cursor()
            query = "delete from details where RoomNo=%s"
            value = (self.var_room_no.get(),)
            my_cursor.execute(query, value)
            conn.commit()
            self.fetch_data()
            conn.close()

    def reset(self):
        self.var_room_no.set("")
        self.var_room_type.set("")

if __name__ == "__main__":
    root = tk.Tk()
    obj = DetailsRoom(root)
    root.mainloop()
