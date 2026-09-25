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
            "defines": [
                "NAPI_CPP_EXCEPTIONS"
            ]
        }
    ]
}
