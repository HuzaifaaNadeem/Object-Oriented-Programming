#include <iostream>
#include <string>

using namespace std;

class Mobile {
private:
    string brand;
    string modelName;
    string screenResolution;
    int ramSize;
    int internalStorage;
    int totalStorage;

public:
    void setBrand(const string& b) {
        brand = b;
    }

    void setModelName(const string& m) {
        modelName = m;
    }

    void setScreenResolution(const string& sr) {
        screenResolution = sr;
    }

    void setRamSize(int r) {
        ramSize = r;
    }

    void setInternalStorage(int is) {
        internalStorage = is;
    }

    void setTotalStorage(int ts) {
        totalStorage = ts;
    }

    string getBrand() const {
        return brand;
    }

    string getModelName() const {
        return modelName;
    }

    string getScreenResolution() const {
        return screenResolution;
    }

    int getRamSize() const {
        return ramSize;
    }

    int getInternalStorage() const {
        return internalStorage;
    }

    int getTotalStorage() const {
        return totalStorage;
    }

    void makePhoneCall(const string& phoneNumber) const {
        cout << "Calling " << phoneNumber << "..." << endl;
    }

    void sendTextMessage(const string& phoneNumber, const string& message) const {
        cout << "Sending message to " << phoneNumber << ": " << message << endl;
    }

    void connectToWifi(const string& networkName) const {
        cout << "Connecting to Wi-Fi network: " << networkName << "..." << endl;
    }

    void openBrowser(const string& url) const {
        cout << "Opening browser at: " << url << "..." << endl;
    }
};

int main() {
    Mobile mobile1;
    mobile1.setBrand("Samsung");
    mobile1.setModelName("Galaxy S21");
    mobile1.setScreenResolution("2400 x 1080");
    mobile1.setRamSize(8);
    mobile1.setInternalStorage(128);
    mobile1.setTotalStorage(256);

    cout << "Mobile 1 Details: " << endl;
    cout << "Brand: " << mobile1.getBrand() << endl;
    cout << "Model: " << mobile1.getModelName() << endl;
    cout << "Resolution: " << mobile1.getScreenResolution() << endl;
    cout << "RAM: " << mobile1.getRamSize() << " GB" << endl;
    cout << "Internal Storage: " << mobile1.getInternalStorage() << " GB" << endl;
    cout << "Total Storage: " << mobile1.getTotalStorage() << " GB" << endl;

    string phoneNumber, message;
    
    cout << "Enter phone number to call: ";
    getline(cin, phoneNumber);
    mobile1.makePhoneCall(phoneNumber);
    
    cout << "Enter phone number to send message: ";
    getline(cin, phoneNumber);
    cout << "Enter your message: ";
    getline(cin, message);
    mobile1.sendTextMessage(phoneNumber, message);
    
    return 0;
}

