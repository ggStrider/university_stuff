#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Player {
    string name;
    string position;
    int goals;
    int matches;
    double rating;
};

vector<Player> team;

void addPlayer() {
    Player newPlayer;

    cout << "Enter player name: ";
    cin >> newPlayer.name;

    cout << "Enter position: ";
    cin >> newPlayer.position;

    cout << "Enter number of goals: ";
    cin >> newPlayer.goals;

    cout << "Enter number of matches: ";
    cin >> newPlayer.matches;

    cout << "Enter average rating: ";
    cin >> newPlayer.rating;

    team.push_back(newPlayer);
    cout << "Player added successfully!" << endl;
}

void showPlayers() {
    for (auto &player : team) {
        cout << "=====================\n";
        cout << "Name: " << player.name << endl;
        cout << "Position: " << player.position << endl;
        cout << "Goals: " << player.goals << endl;
        cout << "Matches: " << player.matches << endl;
        cout << "Rating: " << player.rating << endl;
        cout << "=====================\n";
    }
}

void findPlayersByPosition() {
    cout << "Enter position to search: ";
    string position;
    cin >> position;

    for (auto &player : team) {
        if (player.position == position) {
            cout << "Name: " << player.name << ", Goals: " << player.goals << ", Rating: " << player.rating << endl;
        }
    }
}

void calculateTotalGoals() {
    int totalGoals = 0;
    for (size_t i = 0; i < team.size(); i++) {
        totalGoals += team[i].goals;
    }
    cout << "Total goals scored by the team: " << totalGoals << endl;
}

void findTopScorer() {
    if (team.empty()) {
        cout << "No players in the team!" << endl;
        return;
    }

    Player topScorer = team[0];
    for (auto i = 1; i < team.size(); i++) {
        if (team[i].goals > topScorer.goals) {
            topScorer = team[i];
        }
    }
    cout << "Top scorer: " << topScorer.name << " with " << topScorer.goals << " goals." << endl;
}

void chooseOptimalTeam() {
    if (team.empty()) {
        cout << "No players in the team!" << endl;
        return;
    }

    int n;
    cout << "Enter the number of players for the optimal team: ";
    cin >> n;

    if (n > team.size()) {
        cout << "Not enough players in the team!" << endl;
        return;
    }

    vector<Player> sortedTeam = team;

    for (size_t i = 0; i < sortedTeam.size() - 1; i++) {
        for (size_t j = 0; j < sortedTeam.size() - i - 1; j++) {
            if (sortedTeam[j].rating < sortedTeam[j + 1].rating) {
                swap(sortedTeam[j], sortedTeam[j + 1]);
            }
        }
    }

    cout << "\nOptimal Team (Top " << n << " Players by Rating):\n";
    for (int i = 0; i < n; i++) {
        cout << "Name: " << sortedTeam[i].name
             << ", Rating: " << sortedTeam[i].rating
             << ", Position: " << sortedTeam[i].position
             << endl;
    }
}


void updatePlayerStats() {
    cout << "Enter player name to update: ";
    string name;
    cin >> name;

    for (auto &player : team) {
        if (player.name == name) {
            cout << "Enter new number of goals: ";
            cin >> player.goals;

            cout << "Enter new number of matches: ";
            cin >> player.matches;

            cout << "Enter new average rating: ";
            cin >> player.rating;

            cout << "Player stats updated successfully!" << endl;
            return;
        }
    }
    cout << "Player not found!" << endl;
}

void removePlayer() {
    if (team.empty()) {
        cout << "The team is empty! Nothing to remove." << endl;
        return;
    }

    cout << "Enter the name of the player to remove: ";
    string name;
    cin >> name;

    for (size_t i = 0; i < team.size(); i++) {
        if (team[i].name == name) {
            team.erase(team.begin() + i);
            cout << "Player " << name << " has been removed successfully!" << endl;
            return;
        }
    }

    cout << "Player not found!" << endl;
}

int main() {
    int choice;

    while (true) {
        cout << "\n1 - Add player\n2 - Show all players\n3 - Find players by position\n";
        cout << "4 - Calculate total goals\n5 - Find top scorer\n6 - Update player stats\n7 - Choose "
                "optimal team \n8 - Remove player \n9 - Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addPlayer();
                break;
            case 2:
                showPlayers();
                break;
            case 3:
                findPlayersByPosition();
                break;
            case 4:
                calculateTotalGoals();
                break;
            case 5:
                findTopScorer();
                break;
            case 6:
                updatePlayerStats();
                break;
            case 7:
                chooseOptimalTeam();
                break;
            case 8:
                removePlayer();
                break;
            case 9:
                return 0;
            default:
                cout << "Invalid choice. Try again!" << endl;
        }
    }
}
