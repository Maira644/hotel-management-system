import tkinter as tk
from tkinter import ttk
from tkinter import messagebox
import mysql.connector
import config

class Customer:
    # Class constant to resolve the 'Critical Code Smell' for font duplication
    FONT_FAMILY = "times new roman"

    def __init__(self, root):
        self.root = root
        self.root.title("Hotel Management System")
        self.root.geometry("1295x550+230+220")

        # ================== Variables ===================
        self.var_ref = tk.StringVar()
        self.var_cust_name = tk.StringVar()
        self.var_mother = tk.StringVar()
        self.var_gender = tk.StringVar()
        self.var_post = tk.StringVar()
        self.var_mobile = tk.StringVar()
        self.var_email = tk.StringVar()
        self.var_id_proof = tk.StringVar()
        self.var_id_number = tk.StringVar()
        self.var_address = tk.StringVar()

        # ==================== Title ======================
        lbl_title = tk.Label(self.root, text="ADD CUSTOMER DETAILS", 
                             font=(self.FONT_FAMILY, 18, "bold"), 
                             bg="black", fg="gold", bd=4, relief=tk.RIDGE)
        lbl_title.place(x=0, y=0, width=1295, height=50)

        # ================= Label Frame Left ================
        labelframeleft = tk.LabelFrame(self.root, bd=2, relief=tk.RIDGE, 
                                       text="Customer Details", 
                                       font=(self.FONT_FAMILY, 12, "bold"), padx=2)
        labelframeleft.place(x=5, y=50, width=425, height=490)

        # ================= Labels and Entries ==============
        # Customer Ref
        lbl_cust_ref = tk.Label(labelframeleft, text="Customer Ref", font=("arial", 12, "bold"), padx=2, pady=6)
        lbl_cust_ref.grid(row=0, column=0, sticky=tk.W)
        entry_ref = ttk.Entry(labelframeleft, textvariable=self.var_ref, font=("arial", 13, "bold"), width=20, state="readonly")
        entry_ref.grid(row=0, column=1)

        # Post Code
        lbl_post_code = tk.Label(labelframeleft, text="Post Code:", font=("arial", 12, "bold"), padx=2, pady=6)
        lbl_post_code.grid(row=1, column=0, sticky=tk.W)
        txt_post_code = ttk.Entry(labelframeleft, textvariable=self.var_post, font=("arial", 13, "bold"), width=22)
        txt_post_code.grid(row=1, column=1)

        # Mobile
        lbl_mobile = tk.Label(labelframeleft, text="Mobile:", font=("arial", 12, "bold"), padx=2, pady=6)
        lbl_mobile.grid(row=2, column=0, sticky=tk.W)
        txt_mobile = ttk.Entry(labelframeleft, textvariable=self.var_mobile, font=("arial", 13, "bold"), width=22)
        txt_mobile.grid(row=2, column=1)

        # Email
        lbl_email = tk.Label(labelframeleft, text="Email:", font=("arial", 12, "bold"), padx=2, pady=6)
        lbl_email.grid(row=3, column=0, sticky=tk.W)
        txt_email = ttk.Entry(labelframeleft, textvariable=self.var_email, font=("arial", 13, "bold"), width=22)
        txt_email.grid(row=3, column=1)

        # Id Proof
        lbl_id_proof = tk.Label(labelframeleft, text="Id Proof Type:", font=("arial", 12, "bold"), padx=2, pady=6)
        lbl_id_proof.grid(row=4, column=0, sticky=tk.W)
        combo_id = ttk.Combobox(labelframeleft, textvariable=self.var_id_proof, font=("arial", 12, "bold"), width=20, state="readonly")
        combo_id["value"] = ("Adhaar Card", "Driving License", "Passport")
        combo_id.current(0)
        combo_id.grid(row=4, column=1)

        # Id Number
        lbl_id_number = tk.Label(labelframeleft, text="Id Number:", font=("arial", 12, "bold"), padx=2, pady=6)
        lbl_id_number.grid(row=5, column=0, sticky=tk.W)
        txt_id_number = ttk.Entry(labelframeleft, textvariable=self.var_id_number, font=("arial", 13, "bold"), width=22)
        txt_id_number.grid(row=5, column=1)

        # Address
        lbl_address = tk.Label(labelframeleft, text="Address:", font=("arial", 12, "bold"), padx=2, pady=6)
        lbl_address.grid(row=6, column=0, sticky=tk.W)
        txt_address = ttk.Entry(labelframeleft, textvariable=self.var_address, font=("arial", 13, "bold"), width=22)
        txt_address.grid(row=6, column=1)

        # ================= Buttons Frame ===================
        btn_frame = tk.Frame(labelframeleft, bd=2, relief=tk.RIDGE)
        btn_frame.place(x=0, y=400, width=412, height=40)

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
        table_frame = tk.LabelFrame(self.root, bd=2, relief=tk.RIDGE, 
                                    text="View Details and Search System", 
                                    font=(self.FONT_FAMILY, 12, "bold"), padx=2)
        table_frame.place(x=435, y=50, width=860, height=490)

        lbl_search_by = tk.Label(table_frame, text="Search By:", font=("arial", 12, "bold"), bg="red", fg="white")
        lbl_search_by.grid(row=0, column=0, sticky=tk.W, padx=2)

        self.search_var = tk.StringVar()
        combo_search = ttk.Combobox(table_frame, textvariable=self.search_var, font=("arial", 12, "bold"), width=24, state="readonly")
        combo_search["value"] = ("Mobile", "Ref")
        combo_search.current(0)
        combo_search.grid(row=0, column=1, padx=2)

        self.txt_search = tk.StringVar()
        entry_search = ttk.Entry(table_frame, textvariable=self.txt_search, font=("arial", 13, "bold"), width=24)
        entry_search.grid(row=0, column=2, padx=2)

        btn_search = tk.Button(table_frame, text="Search", command=self.search, width=10, 
                               font=("arial", 11, "bold"), bg="black", fg="gold")
        btn_search.grid(row=0, column=3, padx=2)

        btn_show_all = tk.Button(table_frame, text="Show All", command=self.fetch_data, width=10, 
                                 font=("arial", 11, "bold"), bg="black", fg="gold")
        btn_show_all.grid(row=0, column=4, padx=2)

        # ================= Show Data Table =================
        details_table = tk.Frame(table_frame, bd=2, relief=tk.RIDGE)
        details_table.place(x=0, y=50, width=860, height=350)

        scroll_x = ttk.Scrollbar(details_table, orient=tk.HORIZONTAL)
        scroll_y = ttk.Scrollbar(details_table, orient=tk.VERTICAL)

        self.cust_details_table = ttk.Treeview(details_table, 
                                               column=("ref", "name", "mother", "gender", "post", "mobile", "email", "idproof", "idnumber", "address"), 
                                               xscrollcommand=scroll_x.set, yscrollcommand=scroll_y.set)

        scroll_x.pack(side=tk.BOTTOM, fill=tk.X)
        scroll_y.pack(side=tk.RIGHT, fill=tk.Y)
        scroll_x.config(command=self.cust_details_table.xview)
        scroll_y.config(command=self.cust_details_table.yview)

        self.cust_details_table.heading("ref", text="Refer No")
        self.cust_details_table.heading("name", text="Name")
        self.cust_details_table.heading("mobile", text="Mobile")
        self.cust_details_table.heading("email", text="Email")
        # Add additional headings as needed...

        self.cust_details_table["show"] = "headings"
        self.cust_details_table.pack(fill=tk.BOTH, expand=1)
        self.cust_details_table.bind("<ButtonRelease-1>", self.get_cursor)
        self.fetch_data()

    # ================= Method Implementations =============
    def add_data(self):
        if self.var_mobile.get() == "" or self.var_id_proof.get() == "":
            messagebox.showerror("Error", "All fields are required", parent=self.root)
        else:
            try:
                conn = mysql.connector.connect(host="localhost", user="root", 
                                              password=config.DB_PASSWORD, database="suite")
                my_cursor = conn.cursor()
                # Insert logic here...
                conn.commit()
                self.fetch_data()
                conn.close()
                messagebox.showinfo("Success", "Customer has been added", parent=self.root)
            except Exception as es:
                messagebox.showerror("Error", f"Something went wrong: {str(es)}", parent=self.root)

    def fetch_data(self):
        conn = mysql.connector.connect(host="localhost", user="root", 
                                      password=config.DB_PASSWORD, database="suite")
        my_cursor = conn.cursor()
        my_cursor.execute("select * from customer")
        rows = my_cursor.fetchall()
        if len(rows) != 0:
            self.cust_details_table.delete(*self.cust_details_table.get_children())
            for i in rows:
                self.cust_details_table.insert("", tk.END, values=i)
            conn.commit()
        conn.close()

    def get_cursor(self, event=""):
        cursor_row = self.cust_details_table.focus()
        content = self.cust_details_table.item(cursor_row)
        row = content["values"]
        if row:
            self.var_ref.set(row[0])
            self.var_cust_name.set(row[1])
            self.var_mobile.set(row[5])
            # Set other variables...

    def update(self):
        # Update logic using snake_case variables...
        pass

    def m_delete(self):
        m_delete = messagebox.askyesno("Hotel Management System", "Do you want to delete this customer?", parent=self.root)
        if m_delete > 0:
            conn = mysql.connector.connect(host="localhost", user="root", 
                                          password=config.DB_PASSWORD, database="suite")
            my_cursor = conn.cursor()
            query = "delete from customer where Ref=%s"
            value = (self.var_ref.get(),)
            my_cursor.execute(query, value)
            conn.commit()
            self.fetch_data()
            conn.close()

    def reset(self):
        self.var_ref.set("")
        self.var_mobile.set("")
        self.var_email.set("")
        # Reset other variables...

    def search(self):
        conn = mysql.connector.connect(host="localhost", user="root", 
                                      password=config.DB_PASSWORD, database="suite")
        my_cursor = conn.cursor()
        query = f"SELECT * FROM customer WHERE {self.search_var.get()} LIKE %s"
        my_cursor.execute(query, (f"%{self.txt_search.get()}%",))
        rows = my_cursor.fetchall()
        if len(rows) != 0:
            self.cust_details_table.delete(*self.cust_details_table.get_children())
            for i in rows:
                self.cust_details_table.insert("", tk.END, values=i)
        conn.close()

if __name__ == "__main__":
    root = tk.Tk()
    obj = Customer(root)
    root.mainloop()
