# Allows user to create username and password, then encrypts, and stores the information for later access.

def check_login(user, pswd):
    print("TEST LOGIN")
    print("username: " + user)
    print("password" + pswd)
    # check database

def check_login_dupe(user, pswd):
    print("DUPELICATE?")
    # check database

def register():
    print("Create an account")
    print("Enter:")
    username = input("username: ")
    password = input("password: ")
    check_login_dupe(username, password)

def login():

    print("-- A) Login --")
    print("-- B) Register --")

    choice = input(">> ")

    if (choice == "A" or choice == "a" or choice == "Login"):
        print("Enter your username and password")
        username = input("username: ")
        password = input("password: ")
        check_login(username, password)
    elif(choice == "B" or choice == "b" or choice == "Register"):
        register()
    else:
        print("ERROR")
        login()

login()

