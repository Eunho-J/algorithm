#include <iostream>
#include <vector>

using namespace std;

class Gear
{
private:
    vector<bool> states_is_S;
    int top_idx;
    int score;
public:
    Gear(string str, int score) : 
    score(score)
    {
        for(char c: str)
        {
            states_is_S.push_back(c=='1');
        }
        top_idx = 0;
    };

    bool is_left_S() const
    {
        int left_idx = top_idx - 2;
        if(left_idx < 0)
            left_idx = states_is_S.size() + left_idx;
        return states_is_S[left_idx];
    };

    bool is_right_S() const
    {
        int right_idx = top_idx + 2;
        if(right_idx >= states_is_S.size())
            right_idx = right_idx - states_is_S.size();
        return states_is_S[right_idx];
    };

    int get_score() const
    {
        return states_is_S[top_idx] ? score : 0;
    };

    void print_state() const
    {
        for(auto s: states_is_S)
            cout << s << " ";
        cout << endl;
        for(int i=0; i<states_is_S.size(); i++)
            cout << ((i==top_idx)? "^ " : "  ");
        cout << endl;
    };

    void rotate(int amount)
    {
        top_idx += amount;
        if(top_idx < 0) top_idx += states_is_S.size();
        else if(top_idx >= states_is_S.size()) top_idx -= states_is_S.size();
    }
};

bool is_connected(const Gear& left_gear, const Gear& right_gear)
{   
    bool is_left_S = right_gear.is_left_S();
    bool is_right_S = left_gear.is_right_S();
    return (is_left_S && !is_right_S) || (!is_left_S && is_right_S);
};

class GearBox
{
private:
    vector<Gear> gears;
public:
    GearBox(vector<string> gear_inits, vector<int> gear_scores)
    {
        __glibcxx_assert(gear_inits.size() == gear_scores.size());
        for(int i=0; i<gear_inits.size(); i++)
        {
            gears.emplace_back(gear_inits[i], gear_scores[i]);
        }
    };

    void rotate_at(int index, int amount)
    {
        vector<int> rotate_amounts = vector<int>(gears.size(), 0);
        rotate_amounts[index] = amount;
        // left
        for(int rotating = index; rotating > 0; rotating--)
        {
            if(is_connected(gears[rotating-1], gears[rotating])) 
                rotate_amounts[rotating-1] = -rotate_amounts[rotating];
            else break;
        }
        // right
        for(int rotating = index; rotating < gears.size()-1; rotating++)
        {
            if(is_connected(gears[rotating], gears[rotating+1])) 
                rotate_amounts[rotating+1] = -rotate_amounts[rotating];
            else break;
        }

        for(int i=0; i<gears.size(); i++)
        {
            gears[i].rotate(rotate_amounts[i]);
        }
    }

    int get_score()
    {
        int score = 0;
        for(auto gear: gears)
        {
            score += gear.get_score();
        }
        return score;
    }
};


int main(int argc, char const *argv[])
{
    vector<string> gear_inits;
    vector<int> gear_scores{{1,2,4,8}};
    for(int i=0; i<4; i++)
    {
        string input;
        cin >> input;
        gear_inits.push_back(input);
    }

    GearBox box {gear_inits, gear_scores};

    int k;
    cin >> k;

    for(int i=0; i<k; i++){
        int index, amount;
        cin >> index >> amount;
        box.rotate_at(index-1, -amount);
    }

    cout << box.get_score() << endl;

    return 0;
}
