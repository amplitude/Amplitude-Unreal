# Good Development Resources

- [Introduction to UE4 Plugins](https://wiki.unrealengine.com/An_Introduction_to_UE4_Plugins)
- [MacOS Setup Guide](https://github.com/botman99/ue4-xcode-vscode-mac)
- If you are new to programming in UE4, please see the Epic's [Programming Guide](https://docs.unrealengine.com/latest/INT/Programming/index.html)! 
- Hot Reload: Source code updates should be compiled before reflecting in the editor. Thus, you should do: Window -> Developer Tools -> Modules -> Search `Amplitude` -> Recompile -> Reload. Otherwise, you'll need to restart your UE4Editor
- VSCode Development: By default, UE4 selects XCode as your editor
- Unreal Engine Source Code: Unreal's source code is open source, but you must [link your Epic account to Github](https://www.unrealengine.com/en-US/ue4-on-github).

# Release Process

### PR Commit Title Conventions

PR titles should follow [conventional commit standards](https://www.conventionalcommits.org/en/v1.0.0/). This helps automate the [release](#release) process.

#### Commit Types ([related to release conditions](#release))

- **Special Case**: Any commit with `BREAKING CHANGES` in the body: Creates major release
- `feat(<optional scope>)`: New features (minimum minor release)
- `fix(<optional scope>)`: Bug fixes (minimum patch release)
- `perf(<optional scope>)`: Performance improvement
- `docs(<optional scope>)`: Documentation updates
- `test(<optional scope>)`: Test updates
- `refactor(<optional scope>)`: Code change that neither fixes a bug nor adds a feature
- `style(<optional scope>)`: Code style changes (e.g. formatting, commas, semi-colons)
- `build(<optional scope>)`: Changes that affect the build system or external dependencies (e.g. Yarn, Npm)
- `ci(<optional scope>)`: Changes to our CI configuration files and scripts
- `chore(<optional scope>)`: Other changes that don't modify src or test files
- `revert(<optional scope>)`: Revert commit

### Release [Amplitude Internal]

Releases are managed by [semantic-release](https://github.com/semantic-release/semantic-release). It is a tool that will scan commits since the last release, determine the next [semantic version number](https://semver.org/), publish, and create changelogs.

#### Release Conditions [Amplitude Internal]

- `BREAKING CHANGES` in the body will do a major release
  ```
  feat(cookies): Create new cookie format
  
  BREAKING CHANGES: Breaks old cookie format
  ```
- Else `feat` in title will do a `minor` release
  `feat(cookies): some changes`
- Else `fix` or `perf` in title will do a `patch` release
  `fix: null check bug`
- Else no release
  `docs: update website`
