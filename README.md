
# charm++

![MIT License](https://img.shields.io/github/license/charmbracelet/bubbletea) [![Progress](https://img.shields.io/badge/Progress-6%25-red)](./PROGRESS.md)


charm++ is a set of C++23 bindings for [Charmbracelet](https://charm.sh/)'s TUI framework. It currently includes bindings for the following libraries:
- [Bubble Tea](https://github.com/charmbracelet/bubbletea) (incomplete)

Please note that this is a work in progress and is currently barely functional. The API is still unstable and will certainly change.

## To-do

- Increase support of Bubble Tea
- Port all examples
- Testing
- Write tutorials
- Support other related libraries:
    - [Bubbles](https://github.com/charmbracelet/bubbles)
    - [Harmonica](https://github.com/charmbracelet/harmonica)
    - [Lip Gloss](https://github.com/charmbracelet/lipgloss)
- Python bindings
- Exception wrapping (so we can safely throw from callbacks)
- Ensure thread safety

For more detail, check out the [implementation progress](./PROGRESS.md).
