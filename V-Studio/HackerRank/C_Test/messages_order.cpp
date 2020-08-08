#include "messages_order.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

class Message {
private:
    string message;
    int id;
    static int sequence;
public:
    Message() : message{ "" }, id{ 0 } {}
    Message(const string& message) : message{ message }, id{ Message::sequence++ } {

    }
    const string& get_text() {
        return this->message;
    }

    const int& get_id() {
        return this->id;
    }
};

bool operator<(Message& lhs, Message& rhs) {
    return lhs.get_id() < rhs.get_id();
}

int Message::sequence{ 0 };

class MessageFactory {
public:
    MessageFactory() {}
    Message create_message(const string& text) {
        Message message(text);
        return message;
    }
};

class Recipient {
public:
    Recipient() {}
    void receive(const Message& msg) {
        messages_.push_back(msg);
    }
    void print_messages() {
        fix_order();
        for (auto& msg : messages_) {
            cout << msg.get_text() << endl;
        }
        messages_.clear();
    }
private:
    void fix_order() {
        sort(messages_.begin(), messages_.end());
    }
    vector<Message> messages_;
};

class Network {
public:
    static void send_messages(vector<Message> messages, Recipient& recipient) {
        // simulates the unpredictable network, where sent messages might arrive in unspecified order
        random_shuffle(messages.begin(), messages.end());
        for (auto msg : messages) {
            recipient.receive(msg);
        }
    }
};



int m_o() {
    MessageFactory message_factory;
    Recipient recipient;
    vector<Message> messages;
    string text;
    while (getline(cin, text)) {
        if (text == "") break;
        messages.push_back(message_factory.create_message(text));
    }
    Network::send_messages(messages, recipient);
    recipient.print_messages();
    return 0;
}
