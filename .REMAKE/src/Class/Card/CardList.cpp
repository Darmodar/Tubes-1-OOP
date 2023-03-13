#include "CardList.hpp"

template <class T>
CardList<T>::CardList() {
    this->cards = vector<Card>();
}

template <class T>
CardList<T>::CardList(int totalCard) {
    this->cards = vector<Card>(totalCard);
}

template <class T>
CardList<T>::CardList(string name) {
    this->cards = vector<Card>();
    if (name == "POKER") {
        for (int i = 0; i < 4; i++) {
            for (int j = 1; j <= 13; j++) {
                this->cards.push_back(Card(i, j));
            }
        }
    } else {
        // Bonus spec
        // Exception handling for invalid name
    }
}

template <class T>
CardList<T>::CardList(const CardList& cardList) {
    this->cards = cardList.cards;
}

template <class T>
CardList<T>::~CardList() {
    // Nothing to do
}

template <class T>
int CardList<T>::getTotalCard() const {
    return this->cards.size();
}

template <class T>
T CardList<T>::getCard(int index) const {
    return this->cards[index];
}

template <class T>
vector<T> CardList<T>::getCards() const {
    return this->cards;
}

template <class T>
void CardList<T>::addCard(T card) {
    this->cards.push_back(card);
}

template <class T>
void CardList<T>::removeCard(T card) {
    for (int i = 0; i < this->cards.size(); i++) {
        if (this->cards[i] == card) {
            this->cards.erase(this->cards.begin() + i);
            break;
        }
    }
}

template <class T>
void CardList<T>::removeCard(int index) {
    this->cards.erase(this->cards.begin() + index);
}

template <class T>
void CardList<T>::shuffle() {
    srand(time(NULL));
    for (int i = 0; i < this->cards.size(); i++) {
        int randomIndex = rand() % this->cards.size();
        Card temp = this->cards[i];
        this->cards[i] = this->cards[randomIndex];
        this->cards[randomIndex] = temp;
    }
}

template <class T>
void CardList<T>::sortByNumber() {
    for (int i = 0; i < this->cards.size(); i++) {
        for (int j = i + 1; j < this->cards.size(); j++) {
            if (this->cards[i].getNumber() > this->cards[j].getNumber()) {
                Card temp = this->cards[i];
                this->cards[i] = this->cards[j];
                this->cards[j] = temp;
            }
        }
    }
}

template <class T>
void CardList<T>::sortByNumberDesc() {
    for (int i = 0; i < this->cards.size(); i++) {
        for (int j = i + 1; j < this->cards.size(); j++) {
            if (this->cards[i].getNumber() < this->cards[j].getNumber()) {
                Card temp = this->cards[i];
                this->cards[i] = this->cards[j];
                this->cards[j] = temp;
            }
        }
    }
}

template <class T>
void CardList<T>::sortByColor() {
    for (int i = 0; i < this->cards.size(); i++) {
        for (int j = i + 1; j < this->cards.size(); j++) {
            if (this->cards[i].getColor() > this->cards[j].getColor()) {
                Card temp = this->cards[i];
                this->cards[i] = this->cards[j];
                this->cards[j] = temp;
            }
        }
    }
}

template <class T>
void CardList<T>::print() const {
    for (int i = 0; i < this->cards.size(); i++) {
        cout << this->cards[i] << endl;
    }
}

template <class T>
bool CardList<T>::operator==(const CardList& cardList) const {
    if (this->cards.size() != cardList.cards.size()) {
        return false;
    }
    for (int i = 0; i < this->cards.size(); i++) {
        if (this->cards[i] != cardList.cards[i]) {
            return false;
        }
    }
    return true;
}

template <class T>
bool CardList<T>::operator!=(const CardList& cardList) const {
    return !(*this == cardList);
}

template <class T>
const Card& CardList<T>::operator[](int index) const {
    return this->cards[index];
}

template <class T>
CardList<T>& CardList<T>::operator=(const CardList& cardList) {
    this->cards = cardList.cards;
    return *this;
}

template <class T>
CardList<T>& CardList<T>::operator<<(const Card& card) {
    this->cards.push_back(card);
    return *this;
}

template <class T>
CardList<T>& CardList<T>::operator>>(Card& card) {
    card = this->cards.back();
    this->cards.pop_back();
    return *this;
}