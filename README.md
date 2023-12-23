# Competitive Programming Practice

This repository is dedicated to practicing competitive programming. It contains solutions to various coding problems from different online platforms, along with explanations and approaches.

## LeetCode

### Requirements

- [leetcode-cli](https://github.com/skygragon/leetcode-cli)
  - There is currently an issue where it is not possible to login to LeetCode using the CLI.
  - The workaround is to login to LeetCode using the browser, and then copy the session cookie and CSRF token from the browser to the CLI.
  - After logging in using the browser, create the file `user.json` in `~/.lc/leetcode/` and add the following content:

```json
{
    "login": "<Login Email/Username>",
    "sessionId": "<LEETCODE_SESSION>",
    "sessionCSRF": "<csrftoken>",
    "name": "<LeetCode user ID>,
    "paid": false,
}
```

- VSCode `code` command configured in the PATH environment variable

### Usage

For LeetCode, it is possible to use the bash script `lc` to generate a template solution file. It accepts two arguments: the problem number and the problem name. For example, to generate a template solution file for the problem [Two Sum](https://leetcode.com/problems/two-sum/), run the following command:

```bash
./bin/lc 1 two-sum
```

## License

This repository is licensed under the [BSD-3-Clause License](LICENSE).
