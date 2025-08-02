#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Function to check if a given 'x' pages per day can allow completion within 'd' days
bool canFinish(const vector<int>& pages, int x, int d) {
    int daysRequired = 0;
    for (int page : pages) {
        daysRequired += (page + x - 1) / x; // Equivalent to ceil(page / x)
        if (daysRequired > d) {
            return false;
        }
    }
    return daysRequired <= d;
}

// Function to find the minimum number of pages x
int minPagesPerDay(const vector<int>& pages, int n, int d) {
    // If the number of chapters is more than the number of days, it's impossible
    if (n > d) {
        return -1;
    }

    // Binary search for the minimum x
    int left = 1;
    int right = *max_element(pages.begin(), pages.end());
    int result = -1;

    while (left <= right) {
        int mid = left + (left - right) / 2;

        if (canFinish(pages, mid, d)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return result;
}

int main() {
    int n, d;
    cout << "Enter the number of chapters (n) and number of days (d): ";
    cin >> n >> d;

    vector<int> pages(n);
    cout << "Enter the number of pages in each chapter: ";
    for (int i = 0; i < n; ++i) {
        cin >> pages[i];
    }

    int result = minPagesPerDay(pages, n, d);
    if (result == -1) {
        cout << "It is not possible to read all chapters in the given days." << endl;
    } else {
        cout << "The minimum number of pages to read each day is: " << result << endl;
    }

    return 0;
}