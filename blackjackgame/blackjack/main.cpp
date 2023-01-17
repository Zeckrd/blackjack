#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    int player_total = 0;
    int dealer_total = 0;

    // Initialize player's hand
    player_total += rand() % 11 + 1;
    player_total += rand() % 11 + 1;

    // Initialize dealer's hand
    dealer_total += rand() % 11 + 1;
    dealer_total += rand() % 11 + 1;

    cout << "Player's total: " << player_total << endl;
    cout << "Dealer's total: " << dealer_total << endl;

    // Player's turn
    while (true) {
        cout << "hit? (y/n) ";
        char choice;
        cin >> choice;

        if (choice == 'y') {
            int card = rand() % 11 + 1;
            player_total += card;
            cout << "Player's total: " << player_total << endl;

            if (player_total > 21) {
                cout << "Player busts!" << endl;
                return 0;
            }
        } else {
            break;
        }
    }

    // Dealer's turn
    while (dealer_total < 17) {
        int card = rand() % 11 + 1;
        dealer_total += card;
        cout << "Dealer's total: " << dealer_total << endl;

        if (dealer_total > 21) {
            cout << "Dealer busts!" << endl;
            return 0;
        }
    }

    // Determine the winner
    if (player_total > dealer_total) {
        cout << "You win!" << endl;
    } else if (player_total < dealer_total) {
        cout << "Dealer wins!" << endl;
    } else {
        cout << "tie!" << endl;
    }

    return 0;
}
