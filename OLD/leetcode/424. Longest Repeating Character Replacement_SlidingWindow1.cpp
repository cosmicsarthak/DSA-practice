class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        unordered_map<char, int> mp;
        int mx = -1;
        char max_el;
        string ans;

        int window_start = 0;
        int window_size = 0;

        for (int window_end = 0; window_end < s.size(); window_end++)
        {
            char cur = s.at(window_end);
            int max_freq = 0;
            char max_freq_el = cur;
            ++mp[cur];
            ++window_size;
            for (auto el : mp)
            {
                if (el.second > max_freq) // new max_freq
                {
                    max_freq_el = el.first;
                    max_freq = el.second;
                }
            }

            // int window_size = window_end - window_start + 1;
            // shrink
            if (window_size - max_freq == k)
            {
                // cout << max_freq_el << endl;
            }
            else if (window_size - max_freq > k)
            {
                // cerr << s.substr(window_start, window_size) << "   .. ";
                // cout << s.substr(window_start, window_size) << "..";
                --mp[s.at(window_start)];
                ++window_start;
                --window_size;

                // cout << s.substr(window_start, window_size) << "__" << max_freq_el;

                for (auto el : mp) // new max_freq
                {
                    if (el.second > max_freq)
                    {
                        max_freq_el = el.first;
                        max_freq = el.second;
                    }
                }
                // cout << "-> " << max_freq << "." << max_freq_el << endl;
            }

            if (window_size > mx)
            {
                mx = window_size;
                max_el = max_freq_el;
            }
        }

        for (int i = 0; i < mx; i++)
        {
            ans.push_back(max_el);
        }

        // std::cout << mx;
        return mx;
        // cout << "Ans: " << ans << endl;
    }
};