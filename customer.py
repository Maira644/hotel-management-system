import tkinter as tk
from PIL import Image, ImageTk
from tkinter import ttk
import random
import mysql.connector
from tkinter import messagebox
import config

class Cust_Win:
    def __init__(self, root):
        self.root = root
        self.root.title("customer Window")
        self.root.geometry("1295x550+230+220")

        #=============variable=========================
        self.var_ref = tk.StringVar()
        x = random.randint(1000, 9999)
        self.var_ref.set(str(x))

        self.var_cust_name = tk.StringVar()
        self.var_father = tk.StringVar()
        self.var_gender = tk.StringVar()
        self.var_post = tk.StringVar()
        self.var_mobile = tk.StringVar()
        self.var_email = tk.StringVar()
        self.var_nationality = tk.StringVar()
        self.var_address = tk.StringVar()
        self.var_id_proof = tk.StringVar()
        self.var_id_number = tk.StringVar()

        #====================title======================
        lbl_title = tk.Label(self.root, text="ADD CUSTOMER DETAILS", font=("times new roman", 18, "bold"), bg="black", fg="gray", bd=4, relief=tk.RIDGE)
        lbl_title.place(x=0, y=0, width=1295, height=50)

        #====================logo======================
        img2 = Image.open("logo.jpeg")
        img2 = img2.resize((100, 40), Image.Resampling.LANCZOS)
        self.photoimg2 = ImageTk.PhotoImage(img2)

        lblimg = tk.Label(self.root, image=self.photoimg2, bd=0, relief=tk.RIDGE)
        lblimg.place(x=5, y=2, width=100, height=48)

        #=================label frame====================
        labelframeleft = tk.LabelFrame(self.root, bd=2, relief=tk.RIDGE, text="Customer Details", font=("times new roman", 12, "bold"), padx=2)
        labelframeleft.place(x=5, y=50, width=425, height=490)

        #=================labels and entries==============
        lbl_cust_ref = tk.Label(labelframeleft, text="Customer Ref", font=("arial", 12, "bold"), padx=2, pady=6)
        lbl_cust_ref.grid(row=0, column=0, sticky=tk.W)

        entry_ref = ttk.Entry(labelframeleft, textvariable=self.var_ref, font=("arial", 13, "bold"), width=29, state="readonly")
        entry_ref.grid(row=0, column=1)

        cname = tk.Label(labelframeleft, font=("arial", 12, "bold"), text="Customer Name:", padx=2, pady=6)
        cname.grid(row=1, column=0, sticky=tk.W)
        txtcname = ttk.Entry(labelframeleft, textvariable=self.var_cust_name, font=("arial", 13, "bold"), width=29)
        txtcname.grid(row=1, column=1)

        lblfname = tk.Label(labelframeleft, font=("arial", 12, "bold"), text="Father's Name:", padx=2, pady=6)
        lblfname.grid(row=2, column=0, sticky=tk.W)
        txtfname = ttk.Entry(labelframeleft, textvariable=self.var_father, font=("arial", 13, "bold"), width=29)
        txtfname.grid(row=2, column=1)

        label_gender = tk.Label(labelframeleft, font=("arial", 12, "bold"), text="Gender:", padx=2, pady=6)
        label_gender.grid(row=3, column=0, sticky=tk.W)
        combo_gender = ttk.Combobox(labelframeleft, textvariable=self.var_gender, font=("arial", 12, "bold"), width=27, state="readonly")
        combo_gender["value"] = ("Male", "Female")
        combo_gender.current(0)
        combo_gender.grid(row=3, column=1)

        lblPostCode = tk.Label(labelframeleft, font=("arial", 12, "bold"), text="PostCode:", padx=2, pady=6)
        lblPostCode.grid(row=4, column=0, sticky=tk.W)
        txtPostCode = ttk.Entry(labelframeleft, textvariable=self.var_post, font=("arial", 13, "bold"), width=29)
        txtPostCode.grid(row=4, column=1)

        lblMobile = tk.Label(labelframeleft, font=("arial", 12, "bold"), text="Mobile:", padx=2, pady=6)
        lblMobile.grid(row=5, column=0, sticky=tk.W)
        txtMobile = ttk.Entry(labelframeleft, textvariable=self.var_mobile, font=("arial", 13, "bold"), width=29)
        txtMobile.grid(row=5, column=1)

        lblEmail = tk.Label(labelframeleft, font=("arial", 12, "bold"), text="Email:", padx=2, pady=6)
        lblEmail.grid(row=6, column=0, sticky=tk.W)
        txtEmail = ttk.Entry(labelframeleft, textvariable=self.var_email, font=("arial", 13, "bold"), width=29)
        txtEmail.grid(row=6, column=1)

        lblnationality = tk.Label(labelframeleft, font=("arial", 12, "bold"), text="Nationality:", padx=2, pady=6)
        lblnationality.grid(row=7, column=0, sticky=tk.W)
        combo_Nationality = ttk.Combobox(labelframeleft, textvariable=self.var_nationality, font=("arial", 12, "bold"), width=27, state="readonly")
        combo_Nationality["value"] = ("Pakistani", "American", "Indian", "Chineese", "British", "Arabs", "Other")
        combo_Nationality.current(0)
        combo_Nationality.grid(row=7, column=1)

        lblIdproof = tk.Label(labelframeleft, font=("arial", 12, "bold"), text="Id Proof Type:", padx=2, pady=6)
        lblIdproof.grid(row=8, column=0, sticky=tk.W)
        combo_id = ttk.Combobox(labelframeleft, textvariable=self.var_id_proof, font=("arial", 12, "bold"), width=27, state="readonly")
        combo_id["value"] = ("CNIC", "Driving license", "Passport")
        combo_id.current(0)
        combo_id.grid(row=8, column=1)

        lblIdNumber = tk.Label(labelframeleft, font=("arial", 12, "bold"), text="Id Number:", padx=2, pady=6)
        lblIdNumber.grid(row=9, column=0, sticky=tk.W)
        txtIdNumber = ttk.Entry(labelframeleft, textvariable=self.var_id_number, font=("arial", 13, "bold"), width=29)
        txtIdNumber.grid(row=9, column=1)

        lblAddress = tk.Label(labelframeleft, font=("arial", 12, "bold"), text="Address:", padx=2, pady=6)
        lblAddress.grid(row=10, column=0, sticky=tk.W)
        txtAddress = ttk.Entry(labelframeleft, textvariable=self.var_address, font=("arial", 13, "bold"), width=29)
        txtAddress.grid(row=10, column=1)

        #================button frame====================
        btn_frame = tk.Frame(labelframeleft, bd=2, relief=tk.RIDGE)
        btn_frame.place(x=0, y=400, width=412, height=40)

        btnAdd = tk.Button(btn_frame, text="Add", command=self.add_data, font=("arial", 13, "bold"), bg="black", fg="gray", width=9)
        btnAdd.grid(row=0, column=0, padx=1)

        btnUpdate = tk.Button(btn_frame, text="Update", command=self.update, font=("arial", 13, "bold"), bg="black", fg="gray", width=9)
        btnUpdate.grid(row=0, column=1, padx=1)

        btnDelete = tk.Button(btn_frame, text="Delete", command=self.mDelete, font=("arial", 13, "bold"), bg="black", fg="gray", width=9)
        btnDelete.grid(row=0, column=2, padx=1)

        btnReset = tk.Button(btn_frame, text="Reset", command=self.reset, font=("arial", 13, "bold"), bg="black", fg="gray", width=9)
        btnReset.grid(row=0, column=3, padx=1)

        #==============table frame search system====================
        Table_Frame = tk.LabelFrame(self.root, bd=2, relief=tk.RIDGE, text="View Details And Search System", font=("arial", 12, "bold"), padx=2)
        Table_Frame.place(x=435, y=50, width=860, height=490)

        lblSearchBy = tk.Label(Table_Frame, font=("arial", 12, "bold"), text="Search By:", bg="gray", fg="white")
        lblSearchBy.grid(row=0, column=0, sticky=tk.W, padx=2)
        
        self.search_var = tk.StringVar()
        combo_Search = ttk.Combobox(Table_Frame, textvariable=self.search_var, font=("arial", 12, "bold"), width=24, state="readonly")
        combo_Search["value"] = ("Mobile", "Ref")
        combo_Search.current(0)
        combo_Search.grid(row=0, column=1, padx=2)

        self.txt_search = tk.StringVar()
        txtSearch = ttk.Entry(Table_Frame, textvariable=self.txt_search, font=("arial", 13, "bold"), width=24)
        txtSearch.grid(row=0, column=2, padx=2)

        btnSearch = tk.Button(Table_Frame, text="Search", command=self.search, font=("arial", 11, "bold"), bg="black", fg="gray", width=10)
        btnSearch.grid(row=0, column=3, padx=1)

        btnShowAll = tk.Button(Table_Frame, text="Show All", command=self.fetch_data, font=("arial", 11, "bold"), bg="black", fg="gray", width=10)
        btnShowAll.grid(row=0, column=4, padx=1)

        #==================Show Data Table====================
        details_Table = tk.Frame(Table_Frame, bd=2, relief=tk.RIDGE)
        details_Table.place(x=0, y=50, width=860, height=350)

        scroll_x = ttk.Scrollbar(details_Table, orient=tk.HORIZONTAL)
        scroll_y = ttk.Scrollbar(details_Table, orient=tk.VERTICAL)

        self.Cust_Details_Table = ttk.Treeview(details_Table, column=("ref", "name", "father", "gender", "post", "mobile", "email", "nationality", "idproof", "idnumber", "address"), xscrollcommand=scroll_x.set, yscrollcommand=scroll_y.set)
        scroll_x.pack(side=tk.BOTTOM, fill=tk.X)
        scroll_y.pack(side=tk.RIGHT, fill=tk.Y)

        scroll_x.config(command=self.Cust_Details_Table.xview)
        scroll_y.config(command=self.Cust_Details_Table.yview)

        self.Cust_Details_Table.heading("ref", text="Refer No")
        self.Cust_Details_Table.heading("name", text="Name")
        self.Cust_Details_Table.heading("father", text="Father Name")
        self.Cust_Details_Table.heading("gender", text="Gender")
        self.Cust_Details_Table.heading("post", text="PostCode")
        self.Cust_Details_Table.heading("mobile", text="Mobile")
        self.Cust_Details_Table.heading("email", text="Email")
        self.Cust_Details_Table.heading("nationality", text="Nationality")
        self.Cust_Details_Table.heading("idproof", text="Id Proof")
        self.Cust_Details_Table.heading("idnumber", text="Id Number")
        self.Cust_Details_Table.heading("address", text="Address")

        self.Cust_Details_Table["show"] = "headings"

        self.Cust_Details_Table.column("ref", width=100)
        self.Cust_Details_Table.column("name", width=100)
        self.Cust_Details_Table.column("father", width=100)
        self.Cust_Details_Table.column("gender", width=100)
        self.Cust_Details_Table.column("post", width=100)
        self.Cust_Details_Table.column("mobile", width=100)
        self.Cust_Details_Table.column("email", width=100)
        self.Cust_Details_Table.column("nationality", width=100)
        self.Cust_Details_Table.column("idproof", width=100)
        self.Cust_Details_Table.column("idnumber", width=100)
        self.Cust_Details_Table.column("address", width=100)

        self.Cust_Details_Table.pack(fill=tk.BOTH, expand=1)
        self.Cust_Details_Table.bind("<ButtonRelease-1>", self.get_cursor)
        self.fetch_data()

    def add_data(self):
        if self.var_mobile.get() == "" or self.var_father.get() == "":
            messagebox.showerror("Error", "All fields are required", parent=self.root)
        else:
            try:
                conn = mysql.connector.connect(host="localhost", username="root", password=config.DB_PASSWORD, database="suite")
                my_cursor = conn.cursor()
                my_cursor.execute("INSERT INTO customer VALUES(%s,%s,%s,%s,%s,%s,%s,%s,%s,%s,%s)", (
                    self.var_ref.get(),
                    self.var_cust_name.get(),
                    self.var_father.get(),
                    self.var_gender.get(),
                    self.var_post.get(),
                    self.var_mobile.get(),
                    self.var_email.get(),
                    self.var_nationality.get(),
                    self.var_id_proof.get(),
                    self.var_id_number.get(),
                    self.var_address.get()
                ))
                conn.commit()
                self.fetch_data()
                conn.close()
                messagebox.showinfo("Success", "Customer has been added", parent=self.root)
            except Exception as es:
                messagebox.showwarning("warning", f"Something Went Wrong:{str(es)}", parent=self.root)

    def fetch_data(self):
        conn = mysql.connector.connect(host="localhost", username="root", password=config.DB_PASSWORD, database="suite")
        my_cursor = conn.cursor()
        my_cursor.execute("select * from customer")
        rows = my_cursor.fetchall()
        if len(rows) != 0:
            self.Cust_Details_Table.delete(*self.Cust_Details_Table.get_children())
            for i in rows:
                self.Cust_Details_Table.insert("", tk.END, values=i)
            conn.commit()
        conn.close()

    def get_cursor(self, event=""):
        cursor_row = self.Cust_Details_Table.focus()
        content = self.Cust_Details_Table.item(cursor_row)
        row = content["values"]

        self.var_ref.set(row[0])
        self.var_cust_name.set(row[1])
        self.var_father.set(row[2])
        self.var_gender.set(row[3])
        self.var_post.set(row[4])
        self.var_mobile.set(row[5])
        self.var_email.set(row[6])
        self.var_nationality.set(row[7])
        self.var_id_proof.set(row[8])
        self.var_id_number.set(row[9])
        self.var_address.set(row[10])

    def update(self):
        if self.var_mobile.get() == "":
            messagebox.showerror("Error", "Please Enter Mobile Number", parent=self.root)
        else:
            conn = mysql.connector.connect(host="localhost", username="root", password=config.DB_PASSWORD, database="suite")
            my_cursor = conn.cursor()
            my_cursor.execute("Update customer set Name=%s,Father=%s,Gender=%s,PostCode=%s,Mobile=%s,Email=%s,Nationality=%s,IdProof=%s,IdNumber=%s,Address=%s where Ref=%s", (
                self.var_cust_name.get(),
                self.var_father.get(),
                self.var_gender.get(),
                self.var_post.get(),
                self.var_mobile.get(),
                self.var_email.get(),
                self.var_nationality.get(),
                self.var_id_proof.get(),
                self.var_id_number.get(),
                self.var_address.get(),
                self.var_ref.get()
            ))
            conn.commit()
            self.fetch_data()
            conn.close()
            messagebox.showinfo("Update", "Customer details has been updated successfully", parent=self.root)

    def mDelete(self):
        mDelete = messagebox.askyesno("Inkeeper's Suite", "Do you want delete this customer", parent=self.root)
        if mDelete > 0:
            conn = mysql.connector.connect(host="localhost", username="root", password=config.DB_PASSWORD, database="suite")
            my_cursor = conn.cursor()
            query = "delete from customer where Ref=%s"
            value = (self.var_ref.get(),)
            my_cursor.execute(query, value)
            conn.commit()
            self.fetch_data()
            conn.close()
        else:
            return

    def reset(self):
        self.var_cust_name.set("")
        self.var_father.set("")
        self.var_post.set("")
        self.var_mobile.set("")
        self.var_email.set("")
        self.var_id_number.set("")
        self.var_address.set("")
        
        x = random.randint(1000, 9999)
        self.var_ref.set(str(x))

    def search(self):
        conn = mysql.connector.connect(host="localhost", username="root", password=config.DB_PASSWORD, database="suite")
        my_cursor = conn.cursor()
        my_cursor.execute(
            "SELECT * FROM customer WHERE " + str(self.search_var.get()) + " LIKE %s",
            ('%' + str(self.txt_search.get()) + '%',)
        )
        rows = my_cursor.fetchall()
        if len(rows) != 0:
            self.Cust_Details_Table.delete(*self.Cust_Details_Table.get_children())
            for i in rows:
                self.Cust_Details_Table.insert("", tk.END, values=i)
            conn.commit()
        conn.close()

if __name__ == "__main__":
    root = tk.Tk()
    obj = Cust_Win(root)
    root.mainloop()
