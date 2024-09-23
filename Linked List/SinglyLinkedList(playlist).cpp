#include <iostream>
#include <string>

using namespace std;

class Song {
public:
    string title;
    string artist;
    double duration; // duration in seconds
    Song* next;

    Song(string t, string a, int d) : title(t), artist(a), duration(d), next(nullptr) {}
};

class Playlist {
private:
    Song* head;

public:
    Playlist() : head(nullptr) {}

    void addSongAtBeginning(string title, string artist, double duration)
    {
        Song* newSong = new Song(title, artist, duration);
        newSong->next = head;
        head = newSong;
    }

    // Add song at the beginning
    void addSongAtMiddle(string title, string artist, double duration, int position)
    {
        Song* newSong = new Song(title, artist, duration);
        if(position == 0)
        {
            addSongAtBeginning(title, artist, duration);
            return;
        }
        Song* temp = head;
        for(int i = 0 ; i < position - 1 && temp != nullptr; i++)
        {
            temp = temp->next;
        }
        if(temp == nullptr)
        {
            cout << "Position out of bounds." << endl;
            delete newSong;
        }
        else
        {
            newSong->next = temp->next;
            temp->next = newSong;
        }
    }

    // Remove song by title
    void removeSong(string title)
    {
        if (head == nullptr) return;
        if (head->title == title)
        {
            Song* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Song* temp = head;
        while (temp->next != nullptr && temp->next->title != title)
        {
            temp = temp->next;
        }
        if (temp->next == nullptr)
        {
            cout << "Song not found" << endl;
        }
        else
        {
            Song* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    // Display the entire playlist
    void displayPlaylist()
    {
        Song* temp = head;
        while (temp != nullptr)
        {
            cout << "Title: " << temp->title << ", Artist: " << temp->artist << ", Duration: " << temp->duration << " seconds" << endl;
            temp = temp->next;
        }
    }

    // Play specific song by title
    void playSong(string title)
    {
        Song* temp = head;
        while (temp != nullptr && temp->title != title)
        {
            temp = temp->next;
        }
        if (temp == nullptr)
        {
            cout << "Song not found" << endl;
        }
        else
        {
            cout << "Playing: " << temp->title << " by " << temp->artist << endl;
        }
    }
};

int main()
{
    Playlist myPlaylist;
    int choice;
    string title, artist;
    double duration, position;

    do
    {
        cout << "\nMenu\n";
        cout << "1. Add Song at the begining\n";
        cout << "2. Add Song at the Middle\n";
        cout << "3. Remove Song\n";
        cout << "4. Display playlist\n";
        cout << "5. Play specific song\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter artist: ";
                getline(cin, artist);
                cout << "Enter song duration(in minutes): ";
                cin >> duration;
                myPlaylist.addSongAtBeginning(title, artist, duration);
                break;
            case 2:
                cout << "Enter title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter artist: ";
                getline(cin, artist);
                cout << "Enter song duration(in minutes): ";
                cin >> duration;
                cout << "Enter position to add song: ";
                cin >> position;
                myPlaylist.addSongAtMiddle(title, artist, duration, position);
                break;
            case 3:
                cout << "Enter song to remove: ";
                cin.ignore();
                getline(cin, title);
                myPlaylist.removeSong(title);
                break;
            case 4:
                myPlaylist.displayPlaylist();
                break;
            case 5:
                cout << "Enter song to play: ";
                cin.ignore();
                getline(cin, title);
                myPlaylist.playSong(title);
                break;
            case 6:
                cout << "Exiting..." << endl;
                break;
        }
    } while(choice != 6);

    return 0;
}
