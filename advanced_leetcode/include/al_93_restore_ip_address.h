//
// Created by XieSiqi on 2020/7/21.
//

#ifndef PMLA_AL_93_RESTORE_IP_ADDRESS_H
#define PMLA_AL_93_RESTORE_IP_ADDRESS_H

namespace pmla {

class al_93_restore_ip_address {
public:
    vector<string> restore_ip_addresses(string s) {
        int size = s.length();
        if (size < 4 || size > 12) {
            return res;
        }
        vector<string> path;
        int split = 0, begin = 0;
        dfs(s, size, begin, split, path);
        return res;
    }

    void dfs(string s, int size, int begin, int split, vector<string> path) {
        if (begin == size) {
            if (split == 4) {
                string ip;
                for (int i = 0; i < path.size(); i++) {
                    ip += path[i];
                    if (i == path.size() - 1) {
                        continue;
                    }
                    ip += ".";
                }
                res.push_back(ip);
            }
            return;
        }
        if (size - begin < 1 * (4 - split) || size - begin > 3 * (4 - split)) {
            return;
        }

        for (int i = 0; i < 3; i++) {
            string segment = valid_segment(s, begin, begin + i);
            if (segment != "-1") {
                path.push_back(segment);
                dfs(s, size, begin + i + 1, split + 1, path);
                path.pop_back();
            }
        }
    }

    string valid_segment(string s, int start, int end) {
        int len = end - start + 1;
        if (len > 1 && s[start] == '0') {
            return "-1";
        }
        int segment = 0;
        for (int i = start; i <= end; i++) {
            segment = segment * 10 + (s[i] - '0');
        }
        if (segment > 255) {
            return "-1";
        }
        return to_string(segment);
    }

private:
    vector<string> res;
};

}

#endif //PMLA_AL_93_RESTORE_IP_ADDRESS_H
