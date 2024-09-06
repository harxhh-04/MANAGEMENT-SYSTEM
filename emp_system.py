# importing mysql connector
import mysql.connector 
# making Connection
con = mysql.connector.connect(host="localhost", user="root", password="1234",database="employee")
#creating menu
def menu():
    print("---------------------WELCOME TO EMPLOYEE MANAGEMENT SYSTEM---------------------")
    c='y'
    while c=='y':
        print("1. ADD RECORD")
        print("2. UPDATE RECORD")
        print("3. DELETE RECORD")
        print("4. DISPLAY RECORD")
        print("5. EXIT")
        choice=int(input("ENTER THE CHOICE"))
        if choice==1:
            adddata()
        elif choice==2:
            updatedata()
        elif choice==3:
            deldata()
        elif choice==4:
            fetchdata()
        elif choice==5:
            print("..........Existing.........")
        else:
            print("WRONG INPUT(enter between 1 to 5)")
        c=input("DO YOU WANT TO CONTINUE OR NOT,PRESS Y OR N")
        if c=='y':
            menu()
        else:
            print('THANK YOU!!!!!!')

#ADDING RECORD
def adddata():
    import mysql.connector
    print("........Adding Record.......")
    con=mysql.connector.connect(host='localhost',user='root',password='1234',database='employee')
    if con.is_connected():
        eno=int(input("ENTER THE EMPLOYEE NO"))
        name=input("ENTER THE EMPLOYEE NAME")
        sal=int(input("ENTER THE EMPLOYEE SALARY"))
        data="insert into employees(empno,name,salary) values({},'{}',{})".format(eno,name,sal)
        cur=con.cursor()
        cur.execute(data)
        con.commit()
        print("EMPLOYEE ADDED SUCCESSFULLY")
    else:
        print("SOMETHING WENT WRONG \n TRY AGAIN!!!")
        menu()

#updating record
def updatedata():
    import mysql.connector
    print("........updating records........")
    eno=int(input("ENTER THE EMP NO"))
    sal=int(input("ENTER THE EMP NEW SALARY"))
    try:
        con=mysql.connector.connect(host='localhost',user='root',password='1234',database='employee')
        cur=con.cursor()
        sql="update employees set salary=%d where empno=%d"%(sal,eno)
        cur.execute(sql,)
        print("RECORD UPDATED")
        con.commit()
    except Exception as e:
        print(e)

#DELETING RECORDS
def deldata():
    import mysql.connector
    print(".......Deleting Record........")
    con=mysql.connector.connect(host='localhost',user='root',password='1234',database='employee')
    cur=con.cursor()
    eno=int(input("ENTER THE EMPLOYEE NO"))
    cur.execute("delete from employees where empno=%d"%eno)
    print("RECORD DELETED")
    con.commit()
    menu()

#DISPLAYING RECORDS
def fetchdata():
    import mysql.connector
    print(".......Displaying Records.....")
    con=mysql.connector.connect(host='localhost', user='root',password='1234',database='employee')
    cur=con.cursor()
    cur.execute("select * from employees")
    r=cur.fetchall()
    for i in r:
        print("Employee no : ", i[0])
        print("Employee Name : ", i[1])
        print("Employee Salary : ", i[2])
        print("------------------------------\
	      -----------------------------\
	      ------------------------------\
	      ------------------------------")
    menu()

#calling menu function
menu()
