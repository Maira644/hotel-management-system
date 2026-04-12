from tkinter import*
from PIL import Image,ImageTk
from tkinter import ttk
import random
from time import strftime
from datetime import datetime
import mysql.connector
from tkinter import messagebox

class RoomBooking:
    def __init__(self,root):
        self.root=root
        self.root.title("Room Booking")
        self.root.geometry("1295x550+230+220")

        #==================variables===================
        self.var_contact=StringVar()
        self.var_checkin=StringVar()
        self.var_checkout=StringVar()
        self.var_roomtype=StringVar()
        self.var_roomavailable=StringVar()
        self.var_meal=StringVar()
        self.var_noOfdays=StringVar()
        self.var_paidtax=StringVar()
        self.var_actualtotal=StringVar()
        self.var_total=StringVar()

        #====================title======================
        lbl_title=Label(self.root,text="Room Booking Details",font=("times new roman",18,"bold"),bg="black",fg="gray",bd=4,relief=RIDGE)
        lbl_title.place(x=0,y=0,width=1295,height=50)

        #====================logo======================
        img2=Image.open("logo.jpeg")
        img2=img2.resize((100,40),Image.Resampling.LANCZOS)
        self.photoimg2=ImageTk.PhotoImage(img2)

        lblimg=Label(self.root,image=self.photoimg2,bd=0,relief=RIDGE)
        lblimg.place(x=5,y=2,width=100,height=48)

        #=================label frame====================
        labelframeleft=LabelFrame(self.root,bd=2,relief=RIDGE,text="RoomBooking Details",font=("times new roman",12,"bold"),padx=2)
        labelframeleft.place(x=5,y=50,width=425,height=490)

        #=================labels and entries==============
        #cust Contact
        lbl_cust_contact=Label(labelframeleft,text="Customer Contact",font=("arial",12,"bold"),padx=2,pady=6)
        lbl_cust_contact.grid(row=0,column=0,sticky=W)

        entry_contact=ttk.Entry(labelframeleft,textvariable=self.var_contact,font=("arial",13,"bold"),width=20)
        entry_contact.grid(row=0,column=1,sticky=W)

        #fetch data button
        btnFetchData=Button(labelframeleft, text="Fetch Data", font=("arial", 8, "bold"), bg="black", fg="gray", width=8, command=self.Fetch_contact)
        btnFetchData.place(x=347, y=4)



        #Check_in date
        check_in_date=Label(labelframeleft, text="Check_in Date:", font=("arial",12,"bold"), padx=2, pady=6)
        check_in_date.grid(row=1, column=0, sticky=W)

        txtcheck_in_date=ttk.Entry(labelframeleft, textvariable=self.var_checkin, font=("arial",13,"bold"), width=29)
        txtcheck_in_date.grid(row=1, column=1)

        #check_out date
        lbl_Check_out=Label(labelframeleft,text="Check_Out date:",font=("arial",12,"bold"),padx=2,pady=6)
        lbl_Check_out.grid(row=2,column=0,sticky=W)

        txt_Check_out=ttk.Entry(labelframeleft,textvariable=self.var_checkout,font=("arial",13,"bold"),width=29)
        txt_Check_out.grid(row=2,column=1)

        #Room Typre
        label_RoomType=Label(labelframeleft,text="Room Type:",font=("arial",12,"bold"),padx=2,pady=6)
        label_RoomType.grid(row=3,column=0,sticky=W)

        conn=mysql.connector.connect(host="localhost",username="root",password="1234567890##",database="suite")
        my_cursor=conn.cursor()
        my_cursor.execute("select RoomType from details")
        ide=my_cursor.fetchall()
        combo_RoomType=ttk.Combobox(labelframeleft,textvariable=self.var_roomtype,font=("arial",12,"bold"),width=27,state="readonly")
        combo_RoomType["value"]=ide
        combo_RoomType.current(0)
        combo_RoomType.grid(row=3,column=1)

        #Available Room
        lblRoomAvaialble=Label(labelframeleft,text="Availabe Room:",font=("arial",12,"bold"),padx=2,pady=6)
        lblRoomAvaialble.grid(row=4,column=0,sticky=W)

        conn=mysql.connector.connect(host="localhost",username="root",password="1234567890##",database="suite")
        my_cursor=conn.cursor()
        my_cursor.execute("select RoomNo from details")
        rows=my_cursor.fetchall()

        combo_RoomNo=ttk.Combobox(labelframeleft,textvariable=self.var_roomavailable,font=("arial",12,"bold"),width=27,state="readonly")
        combo_RoomNo["value"]=rows
        combo_RoomNo.current(0)
        combo_RoomNo.grid(row=4,column=1)
        
        

        #Meal
        lblMeal=Label(labelframeleft,text="meal:",font=("arial",12,"bold"),padx=2,pady=6)
        lblMeal.grid(row=5,column=0,sticky=W)

        txtMeal=ttk.Entry(labelframeleft,textvariable=self.var_meal,font=("arial",13,"bold"),width=29)
        txtMeal.grid(row=5,column=1)

        #No. of Days
        lblNoOfDays=Label(labelframeleft,text="No Of Days:",font=("arial",12,"bold"),padx=2,pady=6)
        lblNoOfDays.grid(row=6,column=0,sticky=W)

        txtNoOfDays=ttk.Entry(labelframeleft,textvariable=self.var_noOfdays,font=("arial",13,"bold"),width=29)
        txtNoOfDays.grid(row=6,column=1)

        #Paid Tax
        lblNoOfDays=Label(labelframeleft,text="Paid Tax:",font=("arial",12,"bold"),padx=2,pady=6)
        lblNoOfDays.grid(row=7,column=0,sticky=W)

        txtNoOfDays=ttk.Entry(labelframeleft,textvariable=self.var_paidtax,font=("arial",13,"bold"),width=29)
        txtNoOfDays.grid(row=7,column=1)

        #Sub Total
        lblNoOfDays=Label(labelframeleft,text="Sub Total:",font=("arial",12,"bold"),padx=2,pady=6)
        lblNoOfDays.grid(row=8,column=0,sticky=W)

        txtNoOfDays=ttk.Entry(labelframeleft,textvariable=self.var_actualtotal,font=("arial",13,"bold"),width=29)
        txtNoOfDays.grid(row=8,column=1)

        #Total Cost
        lblIdNumber=Label(labelframeleft,text="Total:",font=("arial",12,"bold"),padx=2,pady=6)
        lblIdNumber.grid(row=9,column=0,sticky=W)

        txtIdNumber=ttk.Entry(labelframeleft,textvariable=self.var_total,font=("arial",13,"bold"),width=29)
        txtIdNumber.grid(row=9,column=1)

        #================Bill Button===============
        btnBill=Button(labelframeleft,text="Bill",command=self.total,font=("arial",13,"bold"),bg="black",fg="gray",width=9)
        btnBill.grid(row=10,column=0,padx=1,sticky=W)

        #================button====================
        btn_frame=Frame(labelframeleft,bd=2,relief=RIDGE)
        btn_frame.place(x=0,y=400,width=412,height=40)

        btnAdd=Button(btn_frame,text="Add",command=self.add_data,font=("arial",13,"bold"),bg="black",fg="gray",width=9)
        btnAdd.grid(row=0,column=0,padx=1)

        btnUpdate=Button(btn_frame,text="Update",command=self.update,font=("arial",13,"bold"),bg="black",fg="gray",width=9)
        btnUpdate.grid(row=0,column=1,padx=1)

        btnDelete=Button(btn_frame,text="Delete",command=self.mDelete,font=("arial",13,"bold"),bg="black",fg="gray",width=9)
        btnDelete.grid(row=0,column=2,padx=1)

        btnReset=Button(btn_frame,text="Reset",command=self.reset,font=("arial",13,"bold"),bg="black",fg="gray",width=9)
        btnReset.grid(row=0,column=3,padx=1)

        #======================Right side image=====================
        img3=Image.open("bedroom.jpeg")
        img3=img3.resize((520,200),Image.Resampling.LANCZOS)
        self.photoimg3=ImageTk.PhotoImage(img3)

        lblimg=Label(self.root,image=self.photoimg3,bd=0,relief=RIDGE)
        lblimg.place(x=760,y=55,width=520,height=200)

         #==============table frame search system====================
        Table_Frame=LabelFrame(self.root,bd=2,relief=RIDGE,text="View Details And Search System",font=("arial",12,"bold"),padx=2)
        Table_Frame.place(x=435,y=280,width=860,height=260)

        lblSearchBy=Label(Table_Frame,font=("arial",12,"bold"),text="Search By:",bg="gray",fg="white")
        lblSearchBy.grid(row=0,column=0,sticky=W,padx=2)
        
        self.search_var=StringVar()
        combo_Search=ttk.Combobox(Table_Frame,textvariable=self.search_var,font=("arial",12,"bold"),width=24,state="readonly")
        combo_Search["value"]=("Contact","roomavailable")
        combo_Search.current(0)
        combo_Search.grid(row=0,column=1,padx=2)

        self.txt_search=StringVar()
        txtSearch=ttk.Entry(Table_Frame,textvariable=self.txt_search,font=("arial",13,"bold"),width=24)
        txtSearch.grid(row=0,column=2,padx=2)

        btnSearch=Button(Table_Frame,text="Search",command=self.search,font=("arial",11,"bold"),bg="black",fg="gray",width=10)
        btnSearch.grid(row=0,column=3,padx=1)

        btnShowAll=Button(Table_Frame,text="Show All",command=self.fetch_data,font=("arial",11,"bold"),bg="black",fg="gray",width=10)
        btnShowAll.grid(row=0,column=4,padx=1)

        #==================Show Data Table====================
        details_Table=Frame(Table_Frame,bd=2,relief=RIDGE)
        details_Table.place(x=0,y=50,width=860,height=180)

        scroll_x=ttk.Scrollbar(details_Table,orient=HORIZONTAL)
        scroll_y=ttk.Scrollbar(details_Table,orient=VERTICAL)

        self.Room_Table=ttk.Treeview(details_Table,column=("contact","checkin","checkout","roomtype","roomavailable","meal","noOfdays"),xscrollcommand=scroll_x.set,yscrollcommand=scroll_y)
        scroll_x.pack(side=BOTTOM,fill=X)
        scroll_y.pack(side=RIGHT,fill=Y)

        scroll_x.config(command=self.Room_Table.xview)
        scroll_y.config(command=self.Room_Table.yview)

        self.Room_Table.heading("contact", text="Contact")
        self.Room_Table.heading("checkin", text="Check_in")
        self.Room_Table.heading("checkout", text="Check_out")
        self.Room_Table.heading("roomtype", text="Room Type")
        self.Room_Table.heading("roomavailable", text="Room Available")
        self.Room_Table.heading("meal", text="Meal")
        self.Room_Table.heading("noOfdays", text="No Of Days")
        

        self.Room_Table["show"]="headings"

        self.Room_Table.column("contact",width=100)
        self.Room_Table.column("checkin",width=100)
        self.Room_Table.column("checkout",width=100)
        self.Room_Table.column("roomtype",width=100)
        self.Room_Table.column("roomavailable",width=100)
        self.Room_Table.column("meal",width=100)
        self.Room_Table.column("noOfdays",width=100)
        self.Room_Table.pack(fill=BOTH,expand=1)

        self.Room_Table.bind("<ButtonRelease-1>",self.get_cursor)
        self.fetch_data()
    #add data
    def add_data(self):
        if self.var_contact.get()=="" or self.var_checkin.get()=="":
            messagebox.showerror("Error","All fields are required",parent=self.root)
        else:
            try:
                conn=mysql.connector.connect(host="localhost",username="root",password=config.DB_PASSWORD,database="suite")
                my_cursor=conn.cursor()
                my_cursor.execute("INSERT INTO room VALUES(%s,%s,%s,%s,%s,%s,%s)",(
                                                                                    self.var_contact.get(),
                                                                                    self.var_checkin.get(),
                                                                                    self.var_checkout.get(),
                                                                                    self.var_roomtype.get(),
                                                                                    self.var_roomavailable.get(),
                                                                                    self.var_meal.get(),
                                                                                    self.var_noOfdays.get()
                                                                               
                                                                            ))
                conn.commit()
                self.fetch_data()
                conn.close()
                messagebox.showinfo("Success","room Booked",parent=self.root)
            except Exception as es:
                messagebox.showwarning("warning",f"Something Went Wrong:{str(es)}",parent=self.root)
    #fetch data 
    def fetch_data(self):
        conn=mysql.connector.connect(host="localhost",username="root",password="1234567890##",database="suite")
        my_cursor=conn.cursor()
        my_cursor.execute("select * from room")
        rows=my_cursor.fetchall()
        if len(rows)!=0:
            self.Room_Table.delete(*self.Room_Table.get_children())
            for i in rows:
                self.Room_Table.insert("",END,values=i)
            conn.commit()
        conn.close()
    
    #get cursor
    def get_cursor(self,event=""):
        cursor_row=self.Room_Table.focus()
        content=self.Room_Table.item(cursor_row)
        row=content["values"]

        self.var_contact.set(row[0])
        self.var_checkin.set(row[1])
        self.var_checkout.set(row[2])
        self.var_roomtype.set(row[3])
        self.var_roomavailable.set(row[4])
        self.var_meal.set(row[5])
        self.var_noOfdays.set(row[6])

    #update function   
    def update(self):
        if self.var_contact.get()=="":
            messagebox.showerror("Error","Please Enter Mobile Number",parent=self.root)
        else:
            conn=mysql.connector.connect(host="localhost",username="root",password="1234567890##",database="suite")
            my_cursor=conn.cursor()
            my_cursor.execute("Update room set Check_in=%s,Check_out=%s,roomtype=%s,roomavailable=%s,meal=%s,noOfdays=%s where Contact=%s",(
                                                                                                                                                                         
                                                                                                                                        self.var_checkin.get(),
                                                                                                                                        self.var_checkout.get(),
                                                                                                                                        self.var_roomtype.get(),
                                                                                                                                        self.var_roomavailable.get(),
                                                                                                                                        self.var_meal.get(),
                                                                                                                                        self.var_noOfdays.get(),
                                                                                                                                        self.var_contact.get()
                                                                                                                                        
                                                                                                                                           ))
            conn.commit()
            self.fetch_data()
            conn.close()
            messagebox.showinfo("Update","Room details has been updated successfully",parent=self.root)

    def mDelete(self):
        mDelete=messagebox.askyesno("Inkeeper's Suite","Do you want to delete this customer",parent=self.root)
        if mDelete>0:
            conn=mysql.connector.connect(host="localhost",username="root",password="1234567890##",database="suite")
            my_cursor=conn.cursor()
            query="delete from room where Contact=%s"
            value=(self.var_contact.get(),)
            my_cursor.execute(query,value)
        else:
            if not mDelete:
                return
        conn.commit()
        self.fetch_data()
        conn.close()

    def reset(self):
        self.var_contact.set("")
        self.var_checkin.set("")
        self.var_checkout.set("")
        self.var_roomtype.set("")
        self.var_roomavailable.set("")
        self.var_meal.set("")
        self.var_noOfdays.set("")
        self.var_paidtax.set("")
        self.var_actualtotal.set("")
        self.var_total.set("")


    #===================All Data Fetch================
    def Fetch_contact(self):
        if self.var_contact.get() == "":
            messagebox.showerror("Error", "Please Enter Contact Number", parent=self.root)
        else:
        # Establish database connection
             conn = mysql.connector.connect(
            host="localhost",
            username="root",
            password="1234567890##",
            database="suite"
        )
        my_cursor = conn.cursor()

        # Fetch Name
        query = "SELECT Name FROM customer WHERE Mobile = %s"
        value = (self.var_contact.get(),)
        my_cursor.execute(query, value)
        name_row = my_cursor.fetchone()

        if name_row is None:
            messagebox.showerror("Error", "This number Not Found", parent=self.root)
            return

        # Fetch Gender
        query = "SELECT Gender FROM customer WHERE Mobile = %s"
        my_cursor.execute(query, value)
        gender_row = my_cursor.fetchone()

        # Fetch Email
        query = "SELECT Email FROM customer WHERE Mobile = %s"
        my_cursor.execute(query, value)
        email_row = my_cursor.fetchone()

        # Fetch Address
        query = "SELECT Address FROM customer WHERE Mobile = %s"
        my_cursor.execute(query, value)
        address_row = my_cursor.fetchone()

        # Fetch Nationality
        query = "SELECT Nationality FROM customer WHERE Mobile = %s"
        my_cursor.execute(query, value)
        nationality_row = my_cursor.fetchone()

        # Close database connection
        conn.commit()
        conn.close()

        # Show Data Frame
        showDataframe = Frame(self.root, bd=4, relief=RIDGE, padx=2)
        showDataframe.place(x=450, y=55, width=300, height=220)

        # Display Name
        lblName = Label(showDataframe, text="Name:", font=("arial", 12, "bold"))
        lblName.place(x=0, y=0)
        lblValueName = Label(showDataframe, text=name_row[0], font=("arial", 12, "bold"))
        lblValueName.place(x=90, y=0)

        # Display Gender
        lblGender = Label(showDataframe, text="Gender:", font=("arial", 12, "bold"))
        lblGender.place(x=0, y=30)
        lblValueGender = Label(showDataframe, text=gender_row[0], font=("arial", 12, "bold"))
        lblValueGender.place(x=90, y=30)

        # Display Email
        lblEmail = Label(showDataframe, text="Email:", font=("arial", 12, "bold"))
        lblEmail.place(x=0, y=60)
        lblValueEmail = Label(showDataframe, text=email_row[0], font=("arial", 12, "bold"))
        lblValueEmail.place(x=90, y=60)

        # Display Address
        lblAddress = Label(showDataframe, text="Address:", font=("arial", 12, "bold"))
        lblAddress.place(x=0, y=90)
        lblValueAddress = Label(showDataframe, text=address_row[0], font=("arial", 12, "bold"))
        lblValueAddress.place(x=90, y=90)

        # Display Nationality
        lblNationality = Label(showDataframe, text="Nationality:", font=("arial", 12, "bold"))
        lblNationality.place(x=0, y=120)
        lblValueNationality = Label(showDataframe, text=nationality_row[0], font=("arial", 12, "bold"))
        lblValueNationality.place(x=90, y=120)

    #search system
    def search(self):
        conn=mysql.connector.connect(host="localhost",username="root",password="1234567890##",database="suite")
        my_cursor=conn.cursor()

        my_cursor.execute(
        "SELECT * FROM room WHERE " + str(self.search_var.get()) + " LIKE %s",
        ('%' + str(self.txt_search.get()) + '%',)
    )
        
    
 
        rows=my_cursor.fetchall()
        if len (rows)!=0:
            self.Room_Table.delete(*self.Room_Table.get_children())
            for i in rows:
                self.Room_Table.insert("",END,values=i)
            conn.commit()
        conn.close()

    def total(self):
    # Parse the dates
        inDate = datetime.strptime(self.var_checkin.get(), "%d/%m/%Y")
        outDate = datetime.strptime(self.var_checkout.get(), "%d/%m/%Y")
    
    # Calculate number of days
        days = (outDate - inDate).days
    
        if days <= 0:  # Invalid check-out date
            messagebox.showerror("Error", "Check-out date must be after check-in date", parent=self.root)
            return
    
        self.var_noOfdays.set(days)

    # Define room and meal rates
        meal_rates = {"Dinner": 300, "Breakfast": 100, "Lunch": 200}
        room_rates = {"Luxury": 700, "Double": 500, "Single": 300}

    # Fetch rates based on user selection
        meal_cost = meal_rates.get(self.var_meal.get(), 0)
        room_cost = room_rates.get(self.var_roomtype.get(), 0)

    # Calculate costs
        base_cost = (meal_cost + room_cost) * days
        tax = base_cost * 0.1  # 10% tax
        total_cost = base_cost + tax

    # Update variables
        self.var_paidtax.set(f"Rs. {tax:.2f}")
        self.var_actualtotal.set(f"Rs. {base_cost:.2f}")
        self.var_total.set(f"Rs. {total_cost:.2f}")







if __name__ == "__main__":
    root=Tk()
    obj=RoomBooking(root)
    root.mainloop()
