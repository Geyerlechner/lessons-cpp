#include <iostream>
#include <string>
struct brief
{
	std::string first_name;
	std::string my_name = "Michael";

	std::string friend_name;
	char		friend_sex = 0;
	int			age = 0;
};

void print(brief e)
{	
	system("CLS");

	std::string sex = (e.friend_sex == 'm') ? "ihn," : "sie,"; 
	std::string age;

	switch(e.age)
	{
	case 12:
		age = "N‰chstes Jahr wirst Du " + std::to_string(e.age + 1) + " sein.";
		break;
	case 17:
		age = "N‰chstes Jahr darfst Du w‰hlen.";
		break;
	case 70:
		age = "Ich hoffe, Du genieﬂt den Ruhestand.";
		break;
	default: 
		std::cout << "Du willst mich auf den Arm nehmen!";
	}

 	std::cout << "Lieber " << e.first_name  << ",\n" 
			  << "Wie geht es Dir? Mir geht es gut. Ich vermisse Dich.\n" 
			  << "Hast Du " << e.friend_name << " in letzter Zeit gesehen?\n"  
			  << "Wenn Du " << e.friend_name << " siehst, bitte " << sex << " mich anzurufen.\n" 
			  << age << std::endl
			  << "Liebe Gruesse\n\n" << e.my_name << std::endl;
}

int main()
{
	brief e;
		
	std::cout << "Geben Sie den Vornamen ein der Person ein, die den Brief erhalten soll \nVorname: ";
	std::cin >> e.first_name;
	
	std::cout << "Geben Sie den Namen ihres Freundes ein!\nName?: ";
	std::cin >> e.friend_name;

	std::cout << "M‰nnlich oder Weiblich ?\nEingabe m oder w?: ";
	std::cin >> e.friend_sex;

	if ( tolower( e.friend_sex ) ==  'm' || tolower ( e.friend_sex ) == 'w' )
		std::cout << "Bitte gib das Alter des Emp‰ngers ein: ";
		std::cin >> e.age;
		print(e);	
		
	
}