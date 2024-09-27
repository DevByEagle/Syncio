#ifndef SYNCIO_UICORE_H
#define SYNCIO_UICORE_H

#ifdef _WIN32
    #include <windows.h>
#else
    #include <X11/Xlib.h>
    #include <X11/Xutil.h>
    #include <unistd.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef __cplusplus
namespace Syncio {
    class UICore {
    public:
        UICore(const char* title, int width, int height);
        ~UICore();
        void mainLoop();
        void render();
        void cleanup();

    private:
        int width;
        int height;
        bool isRunning;

    #ifdef _WIN32
        HWND hwnd;
        HDC hdc;
        static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
    #else
        Display* display;
        Window window;
        GC gc;
    #endif
    };

    // UICore C++ Constructor
    UICore::UICore(const char* title, int width, int height) : width(width), height(height), isRunning(true) {
    #ifdef _WIN32
        WNDCLASS wc = {0};
        wc.lpfnWndProc = UICore::WindowProc;
        wc.hInstance = GetModuleHandle(NULL);
        wc.lpszClassName = "SyncioWindowClass";
        
        RegisterClass(&wc);

        hwnd = CreateWindowEx(
            0, "SyncioWindowClass", title, WS_OVERLAPPEDWINDOW | WS_VISIBLE,
            CW_USEDEFAULT, CW_USEDEFAULT, width, height,
            NULL, NULL, GetModuleHandle(NULL), NULL
        );
        
        if (!hwnd) {
            printf("Failed to create window.\n");
            exit(1);
        }
    #else
        display = XOpenDisplay(NULL);
        if (display == NULL) {
            printf("Failed to open X display.\n");
            exit(1);
        }

        int screen = DefaultScreen(display);
        window = XCreateSimpleWindow(
            display, RootWindow(display, screen), 
            10, 10, width, height, 1, 
            BlackPixel(display, screen), WhitePixel(display, screen)
        );

        XSelectInput(display, window, ExposureMask | KeyPressMask);
        XMapWindow(display, window);

        gc = XCreateGC(display, window, 0, NULL);
    #endif
    }

    // Windows-specific message handler
    #ifdef _WIN32
    LRESULT CALLBACK UICore::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
        if (uMsg == WM_CLOSE) {
            PostQuitMessage(0);
            return 0;
        } else if (uMsg == WM_PAINT) {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            EndPaint(hwnd, &ps);
            return 0;
        }
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
    #endif

    // Main loop for UI Core
    void UICore::mainLoop() {
    #ifdef _WIN32
        MSG msg;
        while (isRunning) {
            while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
                if (msg.message == WM_QUIT) {
                    isRunning = false;
                }
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
            render();
            Sleep(16);
        }
    #else
        XEvent event;
        while (isRunning) {
            XNextEvent(display, &event);
            if (event.type == Expose) {
                render();
            } else if (event.type == KeyPress) {
                isRunning = false;
            }
            usleep(16000);
        }
    #endif
    }

    // Render function for drawing in the window
    void UICore::render() {
    #ifdef _WIN32
        RECT rect;
        GetClientRect(hwnd, &rect);
        FillRect(hdc, &rect, (HBRUSH)(COLOR_WINDOW + 1));
        Rectangle(hdc, 100, 100, 300, 300);
    #else
        XSetForeground(display, gc, BlackPixel(display, DefaultScreen(display)));
        XFillRectangle(display, window, gc, 100, 100, 200, 200);
    #endif
    }

    // Cleanup function for resources
    void UICore::cleanup() {
    #ifdef _WIN32
        DestroyWindow(hwnd);
        PostQuitMessage(0);
    #else
        XDestroyWindow(display, window);
        XCloseDisplay(display);
    #endif
    }

    UICore::~UICore() {
        cleanup();
    }

} // namespace Syncio

#endif // __cplusplus


// C interface for UICore-like functionality

typedef struct {
    int width;
    int height;
    bool isRunning;

#ifdef _WIN32
    HWND hwnd;
    HDC hdc;
#else
    Display* display;
    Window window;
    GC gc;
#endif
} UIWindow;

static UIWindow window;

// C interface functions
void uicore_init(const char* title, int width, int height) {
#ifdef _WIN32
    WNDCLASS wc = {0};
    wc.lpfnWndProc = DefWindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "SyncioCWindowClass";
    
    RegisterClass(&wc);

    window.hwnd = CreateWindowEx(
        0, "SyncioCWindowClass", title, WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        CW_USEDEFAULT, CW_USEDEFAULT, width, height,
        NULL, NULL, GetModuleHandle(NULL), NULL
    );
    
    if (!window.hwnd) {
        printf("Failed to create window.\n");
        exit(1);
    }

#else
    window.display = XOpenDisplay(NULL);
    if (window.display == NULL) {
        printf("Failed to open X display.\n");
        exit(1);
    }

    int screen = DefaultScreen(window.display);
    window.window = XCreateSimpleWindow(
        window.display, RootWindow(window.display, screen), 
        10, 10, width, height, 1, 
        BlackPixel(window.display, screen), WhitePixel(window.display, screen)
    );

    XSelectInput(window.display, window.window, ExposureMask | KeyPressMask);
    XMapWindow(window.display, window.window);

    window.gc = XCreateGC(window.display, window.window, 0, NULL);
#endif
}

void main_loop() {
#ifdef _WIN32
    MSG msg;
    while (window.isRunning) {
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
            if (msg.message == WM_QUIT) {
                window.isRunning = false;
            }
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        // You could call a C-based render function here if needed
        Sleep(16);
    }
#else
    XEvent event;
    while (window.isRunning) {
        XNextEvent(window.display, &event);
        if (event.type == Expose) {
            // C-based rendering function
        } else if (event.type == KeyPress) {
            window.isRunning = false;
        }
        usleep(16000);
    }
#endif
}

void cleanup() {
#ifdef _WIN32
    DestroyWindow(window.hwnd);
    PostQuitMessage(0);
#else
    XDestroyWindow(window.display, window.window);
    XCloseDisplay(window.display);
#endif
}

#endif // UICORE_H
