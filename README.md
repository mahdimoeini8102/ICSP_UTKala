
# ICSP_UTKala
It is my second serious project at the university under the supervision of [Dr. Manouchehr Moradisabzevar](https://ece.ut.ac.ir/en/~moradih) and it's a online shop called UT Kala. (UT stands for University of Tehran and Kala means product in persian)

# Parts of project
In the [CA](https://github.com/mahdimoeini8102/ICSP_UTKala/tree/main/CA) folder you can see the description of the project. There is a [Codes](https://github.com/mahdimoeini8102/ICSP_UTKala/tree/main/Codes) folder in which there are my codes. Lastly, there is an [Executable file](https://github.com/mahdimoeini8102/ICSP_UTKala/tree/main/Executable%20file) and you can download and run it. There are some testcases in [TCs](https://github.com/mahdimoeini8102/ICSP_UTKala/tree/main/TCs) that can help you to work with the program.

# What is it and How it works
This project can be the backend of an online shop that has some buyers, some sellers, and some goods that each has its own characteristics. I’m going to explain commands in which you can enter them in the terminal and work with the program.
|Pattern|Meaning|
|--|--|
|signup \<username> \<password> \<role>|Signup a new person with a specific username and password as seller or buyer (in 'role' position)|
|login \<username> \<password> \<role>|Login a signed up person with a specific username and password as seller or buyer (in 'role' position)|
|logout|The current logged-in person becomes logged out.|
|view|It shows information about the current logged-in person.|
|deposit \<amount_of_money> | Each buyer must have money to buy goods. So, with this command, she/he can increase his/her money.|
|add_goods \<goods_name> \<goods_price> \<goods_count>|Each seller should add some goods to sell using this command.
|show_goods|This command shows all added goods in the shop.|
|buy \<goods_name> \<goods_count> \<seller_username>|Each buyer can buy goods using this command.|
|remove_goods \<goods_name>|This command acts opposite of add_goods command.|
|change_goods_price \<goods_name> \<new_price>|This command is used to change good's price.|
|rate_goods \<goods_name> \<seller_username> \<rating>|Each buyer can rate to each purchased good one time and it must be a number from 1 to 5. If the average score of a product that belongs to a certain seller becomes less than 2 (while at least 5 buyers have rated that product), that seller can no longer sell the mentioned product and if a customer requests to buy it, The item in question should be considered non-existent. If the average score of a product that has been deactivated before becomes greater than or equal to 2 due to the scoring of previous buyers of that product who have not yet registered their score, the product in question will return to normal and until its score is lower again. If it does not exceed 2, it can be sold.|
|search \<number_of_conditions> <br> \<goods_attribute> \<attribute_value> <br> ...|Users can search and view salable products of the system based on one or more specific features. In the first line, the name of the command and then the number of features to be searched are entered. Then <number_of_conditions>, pair of strings of attribute name and attribute value are entered so that there will be two strings in each line. The accepted strings for <goods_attribute> are 4 strings name, min_price, max_price, seller_username.|


