// Programas utilitários para o Cadstro

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cadastro.h"


int pegaCampo(char *l, int nCpo, char *result) {
	char *p, *q, *r;
	int conta=0;
	
	p = l;
	
	while( *p=='"' ) {
		q=p+1;
		while(*q!='"') q++;
		if( nCpo==conta ){
			r=result;
			p++;
			while(p<q) {
				*r = *p;
				p++;
				r++;
				}
			*r='\0';
			return 1;
			}
		else {
			conta++;
			p = q+1;
			while(*p!='"' && *p!='\0' ) p++;
			}
		}
	return 0;
}

void pegaReg(CADBAS *registro, char *linha) {
	pegaCampo( linha, NOME, 		registro->Nome);
	pegaCampo( linha, DESCRICAO_CARGO, 	registro->DescCargo);
	pegaCampo( linha, UORG_LOTACAO, 	registro->uOrg);
	pegaCampo( linha, ORG_LOTACAO, 		registro->Org);
	pegaCampo( linha, ORGSUP_LOTACAO, 	registro->OrgSup);
}

void imprimeReg(CADBAS registro) {
	printf("\nNome:\t%s\nCargo:\t%s\nUOrg:\t%s\nOrg:\t%s\nOrgSup:\t%s\n\n",
		registro.Nome, registro.DescCargo, registro.uOrg, 
		registro.Org, registro.OrgSup);
}






















