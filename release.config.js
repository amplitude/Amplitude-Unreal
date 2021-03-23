module.exports = {
  branches: ["main"],
  plugins: [
    [
      "@semantic-release/commit-analyzer",
      {
        preset: "angular",
        parserOpts: {
          noteKeywords: ["BREAKING CHANGE", "BREAKING CHANGES", "BREAKING"],
        },
      },
    ],
    [
      "@semantic-release/release-notes-generator",
      {
        preset: "angular",
      },
    ],
    [
      "@semantic-release/changelog",
      {
        changelogFile: "CHANGELOG.md",
      },
    ],
    [
      "@google/semantic-release-replace-plugin",
      {
        replacements: [
          {
            files: ["Amplitude.uplugin"],
            from: '"VersionName": ".*"',
            to: '"VersionName": "${nextRelease.version}"',
            results: [
              {
                file: "Amplitude.uplugin",
                hasChanged: true,
                numMatches: 1,
                numReplacements: 1,
              },
            ],
            countMatches: true,
          },
        ],
      },
    ],
    [
      "@semantic-release/git",
      {
        assets: ["Amplitude.uplugin", "CHANGELOG.md"],
        message:
          "chore(release): ${nextRelease.version} [skip ci]\n\n${nextRelease.notes}",
      },
    ],
    [
      "@semantic-release/exec",
      {
        publishCmd: `
          zip -vr AmplitudeUnreal.zip Source Amplitude.uplugin Resources
        `,
      },
    ],
    [
      "@semantic-release/github",
      {
        assets: [{ path: "AmplitudeUnreal.zip" }],
      },
    ],
  ],
};
