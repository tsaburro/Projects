# Allows user to create username and password, then encrypts, and stores the information for later access.

def check_login(user, pswd):
    print("TEST LOGIN")
    print("username: " + user)
    print("password: " + pswd)
    # check database / decrypt password if it exist
    # if username and password pair exists, print out msg saying Complete or something
    # if username and password pair dont exist, print "Username or Password incorrect. Please try again."

def check_login_dupe(user, pswd):
    value = False
    print("DUPELICATE?")
    # check database
    # if in database, set value to True
    # if not, keep as false and send back

    return value

def register():
    print("Create an account")
    print("Enter:")
    username = input("username: ")
    password = input("password: ")
    check_login_dupe(username, password)
    if (check_login_dupe == False):
        print("Create the account and tell user that account is now created")
        # encrypt the password in database
        login()
    elif (check_login_dupe == True):
        print("-- Account already exists. Please enter a different username and password. --")
        register()

def login():

    print("-- A Login --")
    print("-- B Register --")

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

