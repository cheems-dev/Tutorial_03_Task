#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <iostream>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 600;
const unsigned int SCR_HEIGHT = 800;

const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 1.0F, 0, 1.0f);\n"
"}\n\0";//1.0f, 1.0F, 0, 1.0f //Naranja 1.0f, 0.5f, 0.2f, 1.0f

const char* fragmentShaderSource2 = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.5f, 0.2f, 1.0f, 1.0f);\n"
"}\n\0";


const char* fragmentShaderSource3 = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.2f, 0.3f, 0.33f, 1.0f);\n"
"}\n\0";

const char* fragmentShaderSource4 = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.2f, 0.3f, 0.2f, 1.0f);\n"
"}\n\0";

const char* fragmentShaderSource5 = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(1.0f, 0.7f, 0.2f, 1.0f);\n"
"}\n\0";

const char* fragmentShaderSource6 = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.0f, 0.55f, 0.2f, 1.0f);\n"
"}\n\0";



int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Trabajo en clase Computacion Grafica", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }


    // build and compile our shader program
    // ------------------------------------
    // vertex shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    //////////////////////////////////////////////////////////////////////
    unsigned int fragmentshader;
    fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentshader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentshader);
    glGetShaderiv(fragmentshader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentshader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    unsigned int shaderprogram;
    shaderprogram = glCreateProgram();
    glAttachShader(shaderprogram, vertexShader);
    glAttachShader(shaderprogram, fragmentshader);
    glLinkProgram(shaderprogram);
    glGetProgramiv(shaderprogram, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(shaderprogram, 512, NULL, infoLog);
    }
    ///////////////////////////////////////////////////////////////////////////////////////////
    fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentshader, 1, &fragmentShaderSource2, NULL);
    glCompileShader(fragmentshader);
    glGetShaderiv(fragmentshader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentshader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    unsigned int shaderprogram2;
    shaderprogram2 = glCreateProgram();
    glAttachShader(shaderprogram2, vertexShader);
    glAttachShader(shaderprogram2, fragmentshader);
    glLinkProgram(shaderprogram2);
    glGetProgramiv(shaderprogram2, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaderprogram2, 512, NULL, infoLog);
    }

    //----------------------
    fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentshader, 1, &fragmentShaderSource3, NULL);
    glCompileShader(fragmentshader);
    glGetShaderiv(fragmentshader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentshader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    unsigned int shaderprogram3;
    shaderprogram3 = glCreateProgram();
    glAttachShader(shaderprogram3, vertexShader);
    glAttachShader(shaderprogram3, fragmentshader);
    glLinkProgram(shaderprogram3);
    glGetProgramiv(shaderprogram3, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaderprogram3, 512, NULL, infoLog);
    }

    //--------------------


     //----------------------
    fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentshader, 1, &fragmentShaderSource4, NULL);
    glCompileShader(fragmentshader);
    glGetShaderiv(fragmentshader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentshader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    unsigned int shaderprogram4;
    shaderprogram4 = glCreateProgram();
    glAttachShader(shaderprogram4, vertexShader);
    glAttachShader(shaderprogram4, fragmentshader);
    glLinkProgram(shaderprogram4);
    glGetProgramiv(shaderprogram4, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaderprogram4, 512, NULL, infoLog);
    }

    //--------------------

     //----------------------
    fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentshader, 1, &fragmentShaderSource5, NULL);
    glCompileShader(fragmentshader);
    glGetShaderiv(fragmentshader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentshader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    unsigned int shaderprogram5;
    shaderprogram5 = glCreateProgram();
    glAttachShader(shaderprogram5, vertexShader);
    glAttachShader(shaderprogram5, fragmentshader);
    glLinkProgram(shaderprogram5);
    glGetProgramiv(shaderprogram5, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaderprogram5, 512, NULL, infoLog);
    }

    //--------------------

     //----------------------
    fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentshader, 1, &fragmentShaderSource6, NULL);
    glCompileShader(fragmentshader);
    glGetShaderiv(fragmentshader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentshader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
    unsigned int shaderprogram6;
    shaderprogram6 = glCreateProgram();
    glAttachShader(shaderprogram6, vertexShader);
    glAttachShader(shaderprogram6, fragmentshader);
    glLinkProgram(shaderprogram6);
    glGetProgramiv(shaderprogram6, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(shaderprogram6, 512, NULL, infoLog);
    }

    //--------------------


    glDeleteShader(fragmentshader);
    glDeleteShader(vertexShader);

   
    float vertices_1[] = {
        -0.2f, -0.2f, 0.0f,  // left 
         0.0f, -0.1f, 0.0f,  // right
         0.2f, -0.2f, 0.0f,  // top 
    };

    float vestices_2[] = {
         0.0f, -0.1f, 0.0f,  // left 
         0.4f, -0.1f, 0.0f,  // right
         0.2f, -0.2f, 0.0f,   // top 
    };

    float vestices_3[] = {
        0.0f, -0.1f, 0.0f,  // left
        -0.4f, -0.1f, 0.0f,  // right
        -0.2f, -0.2f, 0.0f   // top 
    };

    float vestices_4[] = {
        -0.4f, -0.1f, 0.0f,  // left
        -0.2f, 0.0f, 0.0f,  // right
        0.0f, -0.1f, 0.0f   // top 
    };
    float vestices_5[] = {
        -0.2f, 0.0f, 0.0f,  // left
        0.0f, -0.1f, 0.0f,  // right
        0.2f, 0.0f, 0.0f   // top 
    };
    float vestices_6[] = {
        0.0f, -0.1f, 0.0f,  // left
        0.2f, 0.0f, 0.0f,  // right
        0.4f, -0.1f, 0.0f   // top 
    };

    unsigned int VBO[6], VAO[6];
    glGenVertexArrays(6, VAO);
    glGenBuffers(6, VBO);


    glBindVertexArray(VAO[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices_1), vertices_1, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    
    glBindVertexArray(VAO[1]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[1]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vestices_2), vestices_2, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(VAO[2]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[2]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vestices_3), vestices_3, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);


    
    glBindVertexArray(VAO[3]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[3]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vestices_4), vestices_4, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    glBindVertexArray(VAO[4]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[4]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vestices_5), vestices_5, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);


    
    glBindVertexArray(VAO[5]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[5]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vestices_6), vestices_6, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

 

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(1.0f, 0.5f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glBindVertexArray(VAO[0]);
        glUseProgram(shaderprogram2);
        glDrawArrays(GL_TRIANGLES, 0, 3);


        
        glBindVertexArray(VAO[1]);
        glUseProgram(shaderprogram);
        glDrawArrays(GL_TRIANGLES, 0, 3);


        
        glBindVertexArray(VAO[2]);
        glUseProgram(shaderprogram4);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glBindVertexArray(VAO[3]);
        glUseProgram(shaderprogram5);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glBindVertexArray(VAO[4]);
        glUseProgram(shaderprogram6);
        glDrawArrays(GL_TRIANGLES, 0, 3);


        glBindVertexArray(VAO[5]);
        glUseProgram(shaderprogram3);
        glDrawArrays(GL_TRIANGLES, 0, 3);


        // glDrawElements (GL_TRIANGLES, 9, GL_UNSIGNED_INT, (void *) 0); // Aquí, usa EBO para recuperar los triángulos en los vértices [] que se crearán
        processInput(window);// Presione ESC para salir
        glfwSwapBuffers(window);// Se cambiará el búfer de color (un búfer grande que contiene el valor de color de cada píxel en la ventana GLFW), que se utiliza durante esta iteración para dibujarlo y mostrarlo como salida de pantalla
        glfwPollEvents();// La función verifica si se activa algún evento (como la entrada del teclado o el evento de movimiento del mouse) y actualiza el estado de la ventana. Sin esto, el mouse no se puede mover
    }
    glfwTerminate();// Borrar recursos después de finalizar el programa
    return 0;
    glDeleteBuffers(6, VBO);
    glDeleteVertexArrays(6, VAO);
    glDeleteProgram(shaderprogram);
    glDeleteProgram(shaderprogram2);
}



void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}