package server

import (
	"github.com/labstack/echo"
	"github.com/labstack/echo/v4"
	"github.com/labstack/echo/v4/middleware"
	"net/http"
)

func StartWebServer() {
	// Echo instance
	e := echo.New()

	// Middleware
	e.Use(middleware.Logger())
	e.Use(middleware.Recover())

	// Routes
	e.GET("/", hello)
	// push_stream
	e.GET("/push_stream", push_stream)

	e.GET("/end_stream", end_stream)

	// Start server
	e.Logger.Fatal(e.Start(":1323"))
}

// Handler
func hello(c echo.Context) error {
	return c.String(http.StatusOK, "Hello, World 123 !")
}

func push_stream(c echo.Context) error {
	return c.String(http.StatusOK, "success, push stream.")
}

func end_stream(c echo.Context) error {

	return c.String(http.StatusOK, "success, end stream.")
}
