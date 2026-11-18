{
  "targets": [
    {
      "target_name": "phonestore",
      "sources": [
        "src/wrap.cpp",
        "src/Store.cpp"
      ],
      "include_dirs": [
        "node_modules/node-addon-api"
      ],
      "dependencies": [
        "<!(node -p \"require('node-addon-api').targets\"):node_addon_api_except"
      ],
      "cflags!": [
        "-fno-exceptions"
      ],
      "cflags_cc!": [
        "-fno-exceptions"
      ]
    }
  ]
}

