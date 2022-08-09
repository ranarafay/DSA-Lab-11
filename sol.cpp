#include <iostream>
using namespace std;

// making a class Node which will be used as photos in this program
class Node
{
// made data members public for simplicity
public:
    string Title;
    string Path;
    string DateCreation;
    string Category;
    Node *next;           // for pointing forward
    Node *nextother[10];  // for any other catogorical picture

    // defalut constructor
    Node();
    // destructor
    ~Node();
};
// putline function implementation for class Node 
Node ::Node()
{
    next = NULL;
    for (int i = 0; i < 2; i++)
    {
        nextother[i] = NULL;
    }
}
// ----- class ends -----

// class Linked List names as Photo Organizer
class PhotoOrganizer
{
// made data members public for simplicity
public:
    Node *Head;
    string NameCategory;

    // defailt constructor
    PhotoOrganizer();
};
// outline dunction implementation for class Photo Organizer
PhotoOrganizer ::PhotoOrganizer()
{
    Head = NULL;
}
// ----- class ends -----


// ----- Global Functions -----

// this function will make a list for the categories and return pointer to object 
PhotoOrganizer *AddCategories()
{
    // taking number of categories
    cout << "\nEnter number of Categories you want to manage: ";
    int nocat;
    cin >> nocat;

    // making a list of objects for storing and implementing categories 
    PhotoOrganizer *categories = new PhotoOrganizer[nocat + 1];

    // taking title of each category 
    cout << "\n";
    int j = 0;
    while (j < nocat)
    {
        cout << "Title for Category " << j+1 << ": ";
        cin >> categories[j].NameCategory;
        j++;
    }
    // this title is given har coded for sack of simplicity (it will be used further for termination purpose)
    categories[j].NameCategory = "NULL";
    
    // returning categories
    return categories;
}

// this function will take the categories list and add photos to them by used linked list implementation
PhotoOrganizer *AddPhotos(PhotoOrganizer *categories)
{
    // taking number of photos 
    cout << "\nEnter number of Photots you want to manage: ";
    int nophoto;
    cin >> nophoto;

    // taking the data for the photos one by one and category on each photo
    for (int i = 0; i < nophoto; i++)
    {
        // making a newnode (photo node) for each photo
        Node *newnode = new Node;

        // taking data
        cout << "\nFor Photo " << i + 1 << ": " << endl;
        cout << "Enter Title: ";
        cin >> newnode->Title;
        // cout << "Enter Path: ";
        // cin >> newnode->Path;
        // cout << "Enter Date of Creation: ";
        // cin >> newnode->DateCreation;
        cout << "Enter Category: ";
        cin >> newnode->Category;

        // iterating through the categories list
        int j = 0;
        while (categories[j].NameCategory != "NULL")
        {
            // checking if the category of photo is matching to any category
            if (categories[j].NameCategory == newnode->Category)
            {   
                // if matched
                // adding photos to that category
                // using linked list implementation and logics
                if (categories[j].Head == NULL)
                {
                    categories[j].Head = newnode;
                }

                else
                {
                    Node *temp;
                    temp = categories[j].Head;

                    while (temp->next != NULL)
                    {
                        temp = temp->next;
                    }
                    temp->next = newnode;
                }
            }
            j++;
        }
    }

    // returning categories with photos added 
    return categories;
}

// this function will search photos on the basis of categories
void SearchPhotos(PhotoOrganizer *categories)
{
    // iterating on user choice
    while (true)
    {
        // taking choice
        cout << "\n\nPress: " << endl;
        cout << "1: To search Photos" << endl;
        cout << "2: To Terminate" << endl;
        cout << "Enter: ";
        int choice;
        cin >> choice;

        // if want to search
        if (choice == 1)    
        {
            // taking title of category
            cout << "\nEnter Category: ";
            string cat;
            cin >> cat;

            // taken for checking if category found or not 
            int chk = false;

            // iterating through the categories list
            int k = 0;
            while (categories[k].NameCategory != "NULL")
            {
                // matching if any category in list is matching to given category
                if (categories[k].NameCategory == cat)
                {
                    // if matched
                    chk = true;

                    // printing title of that photo
                    Node *temp;
                    temp = categories[k].Head;

                    if (temp == NULL)
                    {
                        cout << "Nothing found!" << endl;
                    }
                    else
                    {   
                        cout << "\nPictures in Category " << cat << " are: " << endl; 
                        cout << "----------------" << endl;
                        while (temp->next != NULL)
                        {
                            cout << temp->Title << endl;
                            temp = temp->next;
                        }
                        cout << temp->Title << endl;
                        cout << "----------------" << endl;
                    }
                }
                k++;
            }
            // if not matched
            if (chk == false)
            {
                cout << "\nCategory " << cat << " not found!" << endl;
            }
        }
        // if don't want to search
        else if (choice == 2)
        {
            cout << "\nTerminated!\n" << endl;
            break;
        }
        else
        {
            cout << "Reenter Please!" << endl;
            continue;
        }
        
    }
}

void Implementation()
{
    PhotoOrganizer *categories = AddCategories();

    PhotoOrganizer *cat = AddPhotos(categories);

    SearchPhotos(cat);
}

int main()
{
    Implementation();
    return 0;
}