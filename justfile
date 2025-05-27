#!/usr/bin/env -S just --justfile

alias f := fmt
alias c := comply
alias k := check

[doc('List available commands')]
_default:
    just --list --unsorted

[doc('Tasks to make the code-base comply with the rules. Mostly used in git hooks')]
comply: fmt

[doc('Check if the repository comply with the rules and ready to be pushed')]
check: fmt-check

[doc('Clean')]
clean:
    fd -e uf2 -e hex --no-ignore --exec rm

[doc('Format the codebase.')]
fmt:
    dprint fmt

[doc('Check is the codebase properly formatted')]
fmt-check:
    dprint check

