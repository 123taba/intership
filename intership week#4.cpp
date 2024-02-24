

#include <iostream>
#include <list>

using namespace std;

class AuctionItem {
private:
    int bidNumber = 0;
    int itemNumber;
    string description;
    float reservePrice;
    float highestBid = 0;
    bool sold = false;
    float auctionCompanyFee = 0.0;

public:
    AuctionItem(int bd_num, int item_num, string desp, float reserve_price) {
        bidNumber = bd_num;
        itemNumber = item_num;
        description = desp;
        reservePrice = reserve_price;
    }

    void placeBid(float bidAmount) {
        if (bidAmount > highestBid) {
            highestBid = bidAmount;
            bidNumber++;
        }
    }

    void markAsSold() {
        sold = true;
        auctionCompanyFee = highestBid * 0.1; 
    }

    void printItemDetails() {
        cout << "Item Number: " << itemNumber << endl;
        cout << "Description: " << description << endl;
        cout << "Reserve Price: " << reservePrice << endl;
        cout << "Highest Bid: " << highestBid << endl;
        if (sold) {
            cout << "Sold for: " << highestBid << " (including 10% auction company fee: " << auctionCompanyFee << ")" << endl;
        }
        cout << endl;
    }

    bool isReservedMet() const {
        return highestBid >= reservePrice;
    }

    float getHighestBid() const {
        return highestBid;
    }

    float getAuctionCompanyFee() const {
        return auctionCompanyFee;
    }

    int getItemNumber() const {
        return itemNumber;
    }
};

class AuctionSetup {
public:
    list<AuctionItem> itemList;

    void ItemCollection() {
        itemList.push_back(AuctionItem(0, 1, "ITEM 1", 455.5));
        itemList.push_back(AuctionItem(0, 2, "ITEM 2", 5000.5));
        itemList.push_back(AuctionItem(0, 3, "ITEM 3", 4500.3));
        itemList.push_back(AuctionItem(0, 4, "ITEM 4", 4550.5));
        itemList.push_back(AuctionItem(0, 5, "ITEM 5", 4556.5));
        itemList.push_back(AuctionItem(0, 6, "ITEM 6", 4550.5));
        itemList.push_back(AuctionItem(0, 7, "ITEM 7", 6500.7));
        itemList.push_back(AuctionItem(0, 8, "ITEM 8", 2300.3));
        itemList.push_back(AuctionItem(0, 9, "ITEM 9", 7000.8));
        itemList.push_back(AuctionItem(0, 10, "ITEM 10", 2455.5));
    }

    void markItemsAsSold() {
        for (AuctionItem& item : itemList) {
            if (item.isReservedMet()) {
                item.markAsSold();
            }
        }
    }

    void displayResults() {
        float totalFee = 0.0;
        int soldCount = 0;
        int notReservedMetCount = 0;
        int noBidCount = 0;

        for (const AuctionItem& item : itemList) {
            if (item.isReservedMet() && item.getHighestBid() > 0) {
                totalFee += item.getHighestBid() + item.getAuctionCompanyFee();
                soldCount++;
            } else if (!item.isReservedMet()) {
                notReservedMetCount++;
                cout << "Item Number: " << item.getItemNumber() << " - Final Bid: " << item.getHighestBid() << endl;
            } else {
                noBidCount++;
            }
        }
         //noBidCount -= soldCount;

        cout << "Total Fee: " << totalFee << endl;
        cout << "Number of items sold: " << soldCount << endl;
        cout << "Number of items that did not meet the reserve price: " << notReservedMetCount << endl;
        cout << "Number of items with no bids: " << noBidCount << endl;
    }
};

class BuyerBids {
private:
    int buyer_id;
    int item_num;

public:
    void User_Bid_Option() {
        cout << "\n Enter buyer ID for Bidding :";
        cin >> buyer_id;
        cout << "\n Enter Item Number for Bidding : ";
        cin >> item_num;
    }

    void BiddingForItem(AuctionSetup& setuplist) {
        for (AuctionItem& item : setuplist.itemList) {
            if (item_num == item.getItemNumber() ) {
                cout << "\n Item with " << item_num << " Found \n";
                float bidAmount;
                cout << "Enter your bid amount for item " << item_num << ": ";
                cin >> bidAmount;
                item.placeBid(bidAmount);
                return;
            }
        }
        cout << "\n Item with " << item_num << " not found or already sold \n";
    }
};

int main() {
    AuctionSetup auction;
    auction.ItemCollection();
    BuyerBids buyer;
    int choice;

    do {
        cout << "\n1. Place Bid\n2. End Auction\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                buyer.User_Bid_Option();
                buyer.BiddingForItem(auction);
                break;
            case 2:
                auction.markItemsAsSold();
                auction.displayResults();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 2);

    return 0;
}

