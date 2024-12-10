#include <iostream>
#include <regex>
#include <variant>

struct ContactInfo {
    std::string firstname;
    std::string lastname;
    std::string email;
    int age;
    std::string dui;
    std:: string placeWork;
};

struct Contact{

    ContactInfo contact;
    Contact* next; 

    Contact( ContactInfo _contact ): contact( _contact ), next(nullptr){}

};

class ContactService{
    private:
        Contact* headContact = nullptr;
        Contact* finalContact = nullptr;

    public:
        bool insertAtHeadContact( ContactInfo contactData){

            if( isValidDui( contactData.dui ) != true ) return false;

            Contact* newContact = new Contact( contactData );

            if( headContact == nullptr ){
                finalContact = newContact;
            }

            newContact->next = headContact;
            headContact = newContact;

            return true;

        }

        bool insertAtEndContact( ContactInfo contactData ){

            if( isValidDui( contactData.dui ) != true ) return false;
            
            Contact* newContact = new Contact( contactData );

            if( headContact == nullptr ){
                return false;
            }

            finalContact->next = newContact;
        }

        std::variant<Contact, bool> findContactByEmail( std::string email ){

            bool wasFound = false;

            Contact* currentContact = headContact;

            while( currentContact != nullptr ){

                if( currentContact->contact.email == email ) { wasFound = true; break; };

                currentContact = currentContact->next;
            }

            return ( wasFound == true ) ? currentContact : false; 

        }
         bool findContactByTerm( auto term ){
            
        }

        bool isValidDui( std::string dui){
            std::regex pattern("^[0-9]{8}-{1}[0-9]$");
            std::smatch isEqual;

            return ( std::regex_search( dui, isEqual, pattern ) ) ? true : false;
        }

};