#include "client.h"
#include <readline/history.h>

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/

	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log* logger;
	t_config* config;

	/* ---------------- LOGGING ---------------- */

	logger = iniciar_logger();

	// Usando el logger creado previamente
	// Escribi: "Hola! Soy un log"

	logger = log_create("logsTP0.log","logsTP0",true,LOG_LEVEL_INFO);
	log_info(logger,"Hola! Soy un log");
	//log_destroy(logger);


	/* ---------------- ARCHIVOS DE CONFIGURACION ---------------- */
	
	config = iniciar_config();
	config = config_create("/home/utnso/Documents/tp0-Operativos/client/cliente.config");
	

	// Usando el config creado previamente, leemos los valores del config y los 
	// dejamos en las variables 'ip', 'puerto' y 'valor'

	// Loggeamos el valor de config

	ip = config_get_string_value(config, "IP");
	puerto = config_get_string_value(config, "PUERTO");
	valor = config_get_string_value(config, "CLAVE");
	log_info(logger,ip);
	log_info(logger,puerto);
	log_info(logger,valor);

	/* ---------------- LEER DE CONSOLA ---------------- */

	leer_consola(logger);

	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	// ADVERTENCIA: Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo para poder conectarnos a él

	// Creamos una conexión hacia el servidor
	conexion = crear_conexion(ip, puerto);
	// Enviamos al servidor el valor de CLAVE como mensaje
	enviar_mensaje(ip,conexion);
	enviar_mensaje(puerto,conexion);
	enviar_mensaje(valor,conexion);

	// Armamos y enviamos el paquete
	paquete(conexion);

	terminar_programa(conexion, logger, config);

	/*---------------------------------------------------PARTE 5-------------------------------------------------------------*/
	// Proximamente
	// DESTRUIR TODOS

}

t_log* iniciar_logger(void)
{
	t_log* nuevo_logger;
	
	return nuevo_logger;
}

t_config* iniciar_config(void)
{
	t_config* nuevo_config;

	return nuevo_config;
}

void leer_consola(t_log* logger)
{
	char* leido;

    while (1) {
        leido = readline(">");
        if (leido) {
            add_history(leido);
        }
        if (!strncmp(leido, "", 4)) {
            free(leido);
            break;
        }
		log_info(logger,leido);
        free(leido);
    }

	// El resto, las vamos leyendo y logueando hasta recibir un string vacío


	// ¡No te olvides de liberar las lineas antes de regresar!

}

void paquete(int conexion)
{
	// Ahora toca lo divertido!
	char* leido;
	t_paquete* paquete;

	// Leemos y esta vez agregamos las lineas al paquete


	// ¡No te olvides de liberar las líneas y el paquete antes de regresar!
	
}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	/* Y por ultimo, hay que liberar lo que utilizamos (conexion, log y config) 
	  con las funciones de las commons y del TP mencionadas en el enunciado */
	config_destroy(config);
	log_destroy(logger);
	liberar_conexion(conexion);
	  
}
