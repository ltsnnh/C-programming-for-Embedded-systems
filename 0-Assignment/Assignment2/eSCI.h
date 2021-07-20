/*
** ###################################################################
**     Processors:          MPC5517G/E/S
**                          MPC5516G/E/S
**                          MPC5515S
**                          MPC5514G/E
**
**     Reference manual:    MPC5510RM, Rev. 1.1, 04/2012
**
** ###################################################################
*/

/*!
 * @file eSCI.h
 * @version 1.0
 * @date 2021-07-04
 * @brief eSCI Peripheral Access Layer for MPC5510
 *
 * eSCI Peripheral Access Layer for MPC5510 Microcontroller Family
 */

#include <stdint.h>

/* IO definitions (access restrictions to peripheral registers) */
#define     __I     volatile const       /*!< Defines 'read only' permissions */
#define     __O     volatile             /*!< Defines 'write only' permissions */
#define     __IO    volatile             /*!< Defines 'read / write' permissions */

/** eSCI - Register Layout Typedef */
typedef struct {
  __IO  uint32_t CR1;                               /**< Control Register 1, offset: 0x0 */
  __IO  uint16_t CR2;                               /**< Control Register 2, offset: 0x4 */
  __IO  uint16_t DR;                                /**< Data Register, offset: 0x8 */
  __I   uint32_t SR;                                /**< Status Register, offset: 0xC */
  __IO  uint32_t LCR;                               /**< LIN Control Register, offset: 0x10 */
    struct {
        __IO  uint32_t:24;
        __IO  uint32_t L0:1;
        __IO  uint32_t L1:1;
        __IO  uint32_t L2:1;
        __IO  uint32_t L3:1;
        __IO  uint32_t L4:1;
        __IO  uint32_t L5:1;
        __IO  uint32_t L6:1;
        __IO  uint32_t L7:1;
    } LTR;                                          /**< LIN Transmit Register, offset: 0x14 */ 
    struct {
        __IO  uint32_t:24;
        __IO  uint32_t D0:1;
        __IO  uint32_t D1:1;
        __IO  uint32_t D2:1;
        __IO  uint32_t D3:1;
        __IO  uint32_t D4:1;
        __IO  uint32_t D5:1;
        __IO  uint32_t D6:1;
        __IO  uint32_t D7:1;
    } LRR;                                          /**< LIN Receive Register, offset: 0x18 */
    struct {
        __I   uint32_t:16;
        __I   uint32_t P0:1;
        __I   uint32_t P1:1;
        __I   uint32_t P2:1;
        __I   uint32_t P3:1;
        __I   uint32_t P4:1;
        __I   uint32_t P5:1;
        __I   uint32_t P6:1;
        __I   uint32_t P7:1;
        __I   uint32_t P8:1;
        __I   uint32_t P9:1;
        __I   uint32_t P10:1;
        __I   uint32_t P11:1;
        __I   uint32_t P12:1;
        __I   uint32_t P13:1;
        __I   uint32_t P14:1;
        __I   uint32_t P15:1;
    } LPR;                                          /**< LIN Cyclic Redundancy Check (CRC) Register, offset: 0x1C */
/*  __IO  uint32_t LTR;                               /**< LIN Transmit Register, offset: 0x14 */
/*  __IO  uint32_t LRR;                               /**< LIN Receive Register, offset: 0x18 */
/*  __I   uint32_t LPR;                               /**< LIN Cyclic Redundancy Check (CRC) Register, offset: 0x1C */
} ESCI_Type;

/* ----------------------------------------------------------------------------
   -- eSCI Register Masks
   ---------------------------------------------------------------------------- */

/*!
 * @addtogroup ESCI_Register_Masks GPIO Register Masks
 * @{
 */

/*! @name CR1 - ESCI Control Register 1 */
#define ESCI_CR1_SBR_SHIFT                      (0x10u)
#define ESCI_CR1_SBR_MASK                       (0x1FFFu << ESCI_CR1_SBR_SHIFT)
#define ESCI_CR1_SBR(x)                         (((uint32_t)(((uint32_t)(x)) << ESCI_CR1_SBR_SHIFT)) & ESCI_CR1_SBR_MASK)
#define ESCI_CR1_LOOPS_SHIFT                    (0x0Fu)
#define ESCI_CR1_LOOPS_MASK                     (0x01u << ESCI_CR1_LOOPS_SHIFT)
#define ESCI_CR1_LOOPS(x)                       (((uint32_t)(((uint32_t)(x)) << ESCI_CR1_LOOPS_SHIFT)) & ESCI_CR1_LOOPS_MASK)
#define ESCI_CR1_RSRC_SHIFT                     (0x0Du)
#define ESCI_CR1_RSRC_MASK                      (0x01u << ESCI_CR1_RSRC_SHIFT)
#define ESCI_CR1_RSRC(x)                        (((uint32_t)(((uint32_t)(x)) << ESCI_CR1_RSRC_SHIFT)) & ESCI_CR1_RSRC_MASK)
#define ESCI_CR1_M_SHIFT                        (0x0Cu)
#define ESCI_CR1_M_MASK                         (0x01u << ESCI_CR1_M_SHIFT)
#define ESCI_CR1_M(x)                           (((uint32_t)(((uint32_t)(x)) << ESCI_CR1_M_SHIFT)) & ESCI_CR1_M_MASK)
#define ESCI_CR1_WAKE_SHIFT                     (0x0Bu)
#define ESCI_CR1_WAKE_MASK                      (0x01u << ESCI_CR1_WAKE_SHIFT)
#define ESCI_CR1_WAKE(x)                        (((uint32_t)(((uint32_t)(x)) << ESCI_CR1_WAKE_SHIFT)) & ESCI_CR1_WAKE_MASK)
#define ESCI_CR1_ILT_SHIFT                      (0x0Au)
#define ESCI_CR1_ILT_MASK                       (0x01u << ESCI_CR1_ILT_SHIFT)
#define ESCI_CR1_ILT(x)                         (((uint32_t)(((uint32_t)(x)) << ESCI_CR1_ILT_SHIFT)) & ESCI_CR1_ILT_MASK)
#define ESCI_CR1_PE_SHIFT                       (0x09u)
#define ESCI_CR1_PE_MASK                        (0x01u << ESCI_CR1_PE_SHIFT)
#define ESCI_CR1_PE(x)                          (((uint32_t)(((uint32_t)(x)) << ESCI_CR1_PE_SHIFT)) & ESCI_CR1_PE_MASK)
#define ESCI_CR1_PT_SHIFT                       (0x08u)
#define ESCI_CR1_PT_MASK                        (0x01u << ESCI_CR1_PT_SHIFT)
#define ESCI_CR1_PT(x)                          (((uint32_t)(((uint32_t)(x)) << ESCI_CR1_PT_SHIFT)) & ESCI_CR1_PT_MASK)
#define ESCI_CR1_TIE_SHIFT                      (0x07u)
#define ESCI_CR1_TIE_MASK                       (0x01u << ESCI_CR1_TIE_SHIFT)
#define ESCI_CR1_TIE(x)                         (((uint32_t)(((uint32_t)(x)) << ESCI_CR1_TIE_SHIFT)) & ESCI_CR1_TIE_MASK)
#define ESCI_CR1_TCIE_SHIFT                     (0x06u)
#define ESCI_CR1_TCIE_MASK                      (0x01u << ESCI_CR1_TCIE_SHIFT)
#define ESCI_CR1_TCIE(x)                        (((uint32_t)(((uint32_t)(x)) << ESCI_CR1_TCIE_SHIFT)) & ESCI_CR1_TCIE_MASK)
#define ESCI_CR1_RIE_SHIFT                      (0x05u)
#define ESCI_CR1_RIE_MASK                       (0x01u << ESCI_CR1_RIE_SHIFT)
#define ESCI_CR1_RIE(x)                         (((uint32_t)(((uint32_t)(x)) << ESCI_CR1_RIE_SHIFT)) & ESCI_CR1_RIE_MASK)
#define ESCI_CR1_ILIE_SHIFT                     (0x04u)
#define ESCI_CR1_ILIE_MASK                      (0x01u << ESCI_CR1_ILIE_SHIFT)
#define ESCI_CR1_ILIE(x)                        (((uint32_t)(((uint32_t)(x)) << ESCI_CR1_ILIE_SHIFT)) & ESCI_CR1_ILIE_MASK)
#define ESCI_CR1_TE_SHIFT                       (0x03u)
#define ESCI_CR1_TE_MASK                        (0x01u << ESCI_CR1_TE_SHIFT)
#define ESCI_CR1_TE(x)                          (((uint32_t)(((uint32_t)(x)) << ESCI_CR1_TE_SHIFT)) & ESCI_CR1_TE_MASK)
#define ESCI_CR1_RE_SHIFT                       (0x02u)
#define ESCI_CR1_RE_MASK                        (0x01u << ESCI_CR1_RE_SHIFT)
#define ESCI_CR1_RE(x)                          (((uint32_t)(((uint32_t)(x)) << ESCI_CR1_RE_SHIFT)) & ESCI_CR1_RE_MASK)
#define ESCI_CR1_RWU_SHIFT                      (0x01u)
#define ESCI_CR1_RWU_MASK                       (0x01u << ESCI_CR1_RWU_SHIFT)
#define ESCI_CR1_RWU(x)                         (((uint32_t)(((uint32_t)(x)) << ESCI_CR1_RWU_SHIFT)) & ESCI_CR1_RWU_MASK)
#define ESCI_CR1_SBK_SHIFT                      (0x00u)
#define ESCI_CR1_SBK_MASK                       (0x01u << ESCI_CR1_SBK_SHIFT)
#define ESCI_CR1_SBK(x)                         (((uint32_t)(((uint32_t)(x)) << ESCI_CR1_SBK_SHIFT)) & ESCI_CR1_SBK_MASK)

/*! @name CR2 - ESCI Control Register 2 */
#define ESCI_CR2_MDIS_SHIFT                     (0x0Fu)
#define ESCI_CR2_MDIS_MASK                      (0x01u << ESCI_CR2_MDIS_SHIFT)
#define ESCI_CR2_MDIS(x)                        (((uint16_t)(((uint16_t)(x)) << ESCI_CR2_MDIS_SHIFT)) & ESCI_CR2_MDIS_MASK)
#define ESCI_CR2_FBR_SHIFT                      (0x0Eu)
#define ESCI_CR2_FBR_MASK                       (0x01u << ESCI_CR2_FBR_SHIFT)
#define ESCI_CR2_FBR(x)                         (((uint16_t)(((uint16_t)(x)) << ESCI_CR2_FBR_SHIFT)) & ESCI_CR2_FBR_MASK)
#define ESCI_CR2_BSTP_SHIFT                     (0x0Du)
#define ESCI_CR2_BSTP_MASK                      (0x01u << ESCI_CR2_BSTP_SHIFT)
#define ESCI_CR2_BSTP(x)                        (((uint16_t)(((uint16_t)(x)) << ESCI_CR2_BSTP_SHIFT)) & ESCI_CR2_BSTP_MASK)
#define ESCI_CR2_IEBERR_SHIFT                   (0x0Cu)
#define ESCI_CR2_IEBERR_MASK                    (0x01u << ESCI_CR2_IEBERR_SHIFT)
#define ESCI_CR2_IEBERR(x)                      (((uint16_t)(((uint16_t)(x)) << ESCI_CR2_IEBERR_SHIFT)) & ESCI_CR2_IEBERR_MASK)
#define ESCI_CR2_RXDMA_SHIFT                    (0x0Bu)
#define ESCI_CR2_RXDMA_MASK                     (0x01u << ESCI_CR2_RXDMA_SHIFT)
#define ESCI_CR2_RXDMA(x)                       (((uint16_t)(((uint16_t)(x)) << ESCI_CR2_RXDMA_SHIFT)) & ESCI_CR2_RXDMA_MASK)
#define ESCI_CR2_TXDMA_SHIFT                    (0x0Au)
#define ESCI_CR2_TXDMA_MASK                     (0x01u << ESCI_CR2_TXDMA_SHIFT)
#define ESCI_CR2_TXDMA(x)                       (((uint16_t)(((uint16_t)(x)) << ESCI_CR2_TXDMA_SHIFT)) & ESCI_CR2_TXDMA_MASK)
#define ESCI_CR2_BRK13_SHIFT                    (0x09u)
#define ESCI_CR2_BRK13_MASK                     (0x01u << ESCI_CR2_BRK13_SHIFT)
#define ESCI_CR2_BRK13(x)                       (((uint16_t)(((uint16_t)(x)) << ESCI_CR2_BRK13_SHIFT)) & ESCI_CR2_BRK13_MASK)
#define ESCI_CR2_TXDIR_SHIFT                    (0x08u)
#define ESCI_CR2_TXDIR_MASK                     (0x01u << ESCI_CR2_TXDIR_SHIFT)
#define ESCI_CR2_TXDIR(x)                       (((uint16_t)(((uint16_t)(x)) << ESCI_CR2_TXDIR_SHIFT)) & ESCI_CR2_TXDIR_MASK)
#define ESCI_CR2_BESM13_SHIFT                   (0x07u)
#define ESCI_CR2_BESM13_MASK                    (0x01u << ESCI_CR2_BESM13_SHIFT)
#define ESCI_CR2_BESM13(x)                      (((uint16_t)(((uint16_t)(x)) << ESCI_CR2_BESM13_SHIFT)) & ESCI_CR2_BESM13_MASK)
#define ESCI_CR2_SBSTP_SHIFT                    (0x06u)
#define ESCI_CR2_SBSTP_MASK                     (0x01u << ESCI_CR2_SBSTP_SHIFT)
#define ESCI_CR2_SBSTP(x)                       (((uint16_t)(((uint16_t)(x)) << ESCI_CR2_SBSTP_SHIFT)) & ESCI_CR2_SBSTP_MASK)
#define ESCI_CR2_PMSK_SHIFT                     (0x04u)
#define ESCI_CR2_PMSK_MASK                      (0x01u << ESCI_CR2_PMSK_SHIFT)
#define ESCI_CR2_PMSK(x)                        (((uint16_t)(((uint16_t)(x)) << ESCI_CR2_PMSK_SHIFT)) & ESCI_CR2_PMSK_MASK)
#define ESCI_CR2_ORIE_SHIFT                     (0x03u)
#define ESCI_CR2_ORIE_MASK                      (0x01u << ESCI_CR2_ORIE_SHIFT)
#define ESCI_CR2_ORIE(x)                        (((uint16_t)(((uint16_t)(x)) << ESCI_CR2_ORIE_SHIFT)) & ESCI_CR2_ORIE_MASK)
#define ESCI_CR2_NFIE_SHIFT                     (0x02u)
#define ESCI_CR2_NFIE_MASK                      (0x01u << ESCI_CR2_NFIE_SHIFT)
#define ESCI_CR2_NFIE(x)                        (((uint16_t)(((uint16_t)(x)) << ESCI_CR2_NFIE_SHIFT)) & ESCI_CR2_NFIE_MASK)
#define ESCI_CR2_FEIE_SHIFT                     (0x01u)
#define ESCI_CR2_FEIE_MASK                      (0x01u << ESCI_CR2_FEIE_SHIFT)
#define ESCI_CR2_FEIE(x)                        (((uint16_t)(((uint16_t)(x)) << ESCI_CR2_FEIE_SHIFT)) & ESCI_CR2_FEIE_MASK)
#define ESCI_CR2_PFIE_SHIFT                     (0x00u)
#define ESCI_CR2_PFIE_MASK                      (0x01u << ESCI_CR2_PFIE_SHIFT)
#define ESCI_CR2_PFIE(x)                        (((uint16_t)(((uint16_t)(x)) << ESCI_CR2_PFIE_SHIFT)) & ESCI_CR2_PFIE_MASK)

/*! @name DR - ESCI Data Register */
#define ESCI_DR_R8_SHIFT                        (0x0Fu)
#define ESCI_DR_R8_MASK                         (0x01u << ESCI_DR_R8_SHIFT)
#define ESCI_DR_R8(x)                           (((uint16_t)(((uint16_t)(x)) << ESCI_DR_R8_SHIFT)) & ESCI_DR_R8_MASK)
#define ESCI_DR_T8_SHIFT                        (0x0Eu)
#define ESCI_DR_T8_MASK                         (0x01u << ESCI_CR2_T8_SHIFT)
#define ESCI_DR_T8(x)                           (((uint16_t)(((uint16_t)(x)) << ESCI_CR2_T8_SHIFT)) & ESCI_CR2_T8_MASK)
#define ESCI_DR_D_SHIFT                         (0x00u)
#define ESCI_DR_D_MASK                          (0xFFu << ESCI_CR2_D_SHIFT)
#define ESCI_DR_D(x)                            (((uint16_t)(((uint16_t)(x)) << ESCI_CR2_D_SHIFT)) & ESCI_CR2_D_MASK)

/*! @name SR - ESCI Status Register */
#define ESCI_SR_TDRE_SHIFT                      (0x1Fu)
#define ESCI_SR_TDRE_MASK                       (0x01u << ESCI_SR_TDRE_SHIFT)
#define ESCI_SR_TDRE(x)                         (((uint32_t)(((uint32_t)(x)) << ESCI_SR_TDRE_SHIFT)) & ESCI_SR_TDRE_MASK)
#define ESCI_SR_TC_SHIFT                        (0x1Eu)
#define ESCI_SR_TC_MASK                         (0x01u << ESCI_SR_TC_SHIFT)
#define ESCI_SR_TC(x)                           (((uint32_t)(((uint32_t)(x)) << ESCI_SR_TC_SHIFT)) & ESCI_SR_TC_MASK)
#define ESCI_SR_RDRF_SHIFT                      (0x1Du)
#define ESCI_SR_RDRF_MASK                       (0x01u << ESCI_SR_RDRF_SHIFT)
#define ESCI_SR_RDRF(x)                         (((uint32_t)(((uint32_t)(x)) << ESCI_SR_RDRF_SHIFT)) & ESCI_SR_RDRF_MASK)
#define ESCI_SR_IDLE_SHIFT                      (0x1Cu)
#define ESCI_SR_IDLE_MASK                       (0x01u << ESCI_SR_IDLE_SHIFT)
#define ESCI_SR_IDLE(x)                         (((uint32_t)(((uint32_t)(x)) << ESCI_SR_IDLE_SHIFT)) & ESCI_SR_IDLE_MASK)
#define ESCI_SR_OR_SHIFT                        (0x1Bu)
#define ESCI_SR_OR_MASK                         (0x01u << ESCI_SR_OR_SHIFT)
#define ESCI_SR_OR(x)                           (((uint32_t)(((uint32_t)(x)) << ESCI_SR_OR_SHIFT)) & ESCI_SR_OR_MASK)
#define ESCI_SR_NF_SHIFT                        (0x1Au)
#define ESCI_SR_NF_MASK                         (0x01u << ESCI_SR_NF_SHIFT)
#define ESCI_SR_NF(x)                           (((uint32_t)(((uint32_t)(x)) << ESCI_SR_NF_SHIFT)) & ESCI_SR_NF_MASK)
#define ESCI_SR_FE_SHIFT                        (0x19u)
#define ESCI_SR_FE_MASK                         (0x01u << ESCI_SR_FE_SHIFT)
#define ESCI_SR_FE(x)                           (((uint32_t)(((uint32_t)(x)) << ESCI_SR_FE_SHIFT)) & ESCI_SR_FE_MASK)
#define ESCI_SR_PF_SHIFT                        (0x18u)
#define ESCI_SR_PF_MASK                         (0x01u << ESCI_SR_PF_SHIFT)
#define ESCI_SR_PF(x)                           (((uint32_t)(((uint32_t)(x)) << ESCI_SR_PF_SHIFT)) & ESCI_SR_PF_MASK)
#define ESCI_SR_BERR_SHIFT                      (0x14u)
#define ESCI_SR_BERR_MASK                       (0x01u << ESCI_SR_BERR_SHIFT)
#define ESCI_SR_BERR(x)                         (((uint32_t)(((uint32_t)(x)) << ESCI_SR_BERR_SHIFT)) & ESCI_SR_BERR_MASK)
#define ESCI_SR_RAF_SHIFT                       (0x10u)
#define ESCI_SR_RAF_MASK                        (0x01u << ESCI_SR_RAF_SHIFT)
#define ESCI_SR_RAF(x)                          (((uint32_t)(((uint32_t)(x)) << ESCI_SR_RAF_SHIFT)) & ESCI_SR_RAF_MASK)
#define ESCI_SR_RXRDY_SHIFT                     (0x0Fu)
#define ESCI_SR_RXRDY_MASK                      (0x01u << ESCI_SR_RXRDY_SHIFT)
#define ESCI_SR_RXRDY(x)                        (((uint32_t)(((uint32_t)(x)) << ESCI_SR_RXRDY_SHIFT)) & ESCI_SR_RXRDY_MASK)
#define ESCI_SR_TXRDY_SHIFT                     (0x0Eu)
#define ESCI_SR_TXRDY_MASK                      (0x01u << ESCI_SR_TXRDY_SHIFT)
#define ESCI_SR_TXRDY(x)                        (((uint32_t)(((uint32_t)(x)) << ESCI_SR_TXRDY_SHIFT)) & ESCI_SR_TXRDY_MASK)
#define ESCI_SR_LWAKE_SHIFT                     (0x0Du)
#define ESCI_SR_LWAKE_MASK                      (0x01u << ESCI_SR_LWAKE_SHIFT)
#define ESCI_SR_LWAKE(x)                        (((uint32_t)(((uint32_t)(x)) << ESCI_SR_LWAKE_SHIFT)) & ESCI_SR_LWAKE_MASK)
#define ESCI_SR_STO_SHIFT                       (0x0Cu)
#define ESCI_SR_STO_MASK                        (0x01u << ESCI_SR_STO_SHIFT)
#define ESCI_SR_STO(x)                          (((uint32_t)(((uint32_t)(x)) << ESCI_SR_STO_SHIFT)) & ESCI_SR_STO_MASK)
#define ESCI_SR_PBERR_SHIFT                     (0x0Bu)
#define ESCI_SR_PBERR_MASK                      (0x01u << ESCI_SR_PBERR_SHIFT)
#define ESCI_SR_PBERR(x)                        (((uint32_t)(((uint32_t)(x)) << ESCI_SR_PBERR_SHIFT)) & ESCI_SR_PBERR_MASK)
#define ESCI_SR_CERR_SHIFT                      (0x0Au)
#define ESCI_SR_CERR_MASK                       (0x01u << ESCI_SR_CERR_SHIFT)
#define ESCI_SR_CERR(x)                         (((uint32_t)(((uint32_t)(x)) << ESCI_SR_CERR_SHIFT)) & ESCI_SR_CERR_MASK)
#define ESCI_SR_CKERR_SHIFT                     (0x09u)
#define ESCI_SR_CKERR_MASK                      (0x01u << ESCI_SR_CKERR_SHIFT)
#define ESCI_SR_CKERR(x)                        (((uint32_t)(((uint32_t)(x)) << ESCI_SR_CKERR_SHIFT)) & ESCI_SR_CKERR_MASK)
#define ESCI_SR_FRC_SHIFT                       (0x08u)
#define ESCI_SR_FRC_MASK                        (0x01u << ESCI_SR_FRC_SHIFT)
#define ESCI_SR_FRC(x)                          (((uint32_t)(((uint32_t)(x)) << ESCI_SR_FRC_SHIFT)) & ESCI_SR_FRC_MASK)
#define ESCI_SR_UREQ_SHIFT                      (0x01u)
#define ESCI_SR_UREQ_MASK                       (0x01u << ESCI_SR_UREQ_SHIFT)
#define ESCI_SR_UREQ(x)                         (((uint32_t)(((uint32_t)(x)) << ESCI_SR_UREQ_SHIFT)) & ESCI_SR_UREQ_MASK)
#define ESCI_SR_OVFL_SHIFT                      (0x00u)
#define ESCI_SR_OVFL_MASK                       (0x01u << ESCI_SR_OVFL_SHIFT)
#define ESCI_SR_OVFL(x)                         (((uint32_t)(((uint32_t)(x)) << ESCI_SR_OVFL_SHIFT)) & ESCI_SR_OVFL_MASK)

/*! @name LCR - ESCI LIN Control Register */
#define ESCI_LCR_LRES_SHIFT                     (0x1Fu)
#define ESCI_LCR_LRES_MASK                      (0x01u << ESCI_LCR_LRES_SHIFT)
#define ESCI_LCR_LRES(x)                        (((uint32_t)(((uint32_t)(x)) << ESCI_LCR_LRES_SHIFT)) & ESCI_LCR_LRES_MASK)
#define ESCI_LCR_WU_SHIFT                       (0x1Eu)
#define ESCI_LCR_WU_MASK                        (0x01u << ESCI_LCR_WU_SHIFT)
#define ESCI_LCR_WU(x)                          (((uint32_t)(((uint32_t)(x)) << ESCI_LCR_WU_SHIFT)) & ESCI_LCR_WU_MASK)
#define ESCI_LCR_WUD_SHIFT                      (0x1Cu)
#define ESCI_LCR_WUD_MASK                       (0x03u << ESCI_LCR_WUD_SHIFT)
#define ESCI_LCR_WUD(x)                         (((uint32_t)(((uint32_t)(x)) << ESCI_LCR_WUD_SHIFT)) & ESCI_LCR_WUD_MASK)
#define ESCI_LCR_LDBG_SHIFT                     (0x1Bu)
#define ESCI_LCR_LDBG_MASK                      (0x01u << ESCI_LCR_LDBG_SHIFT)
#define ESCI_LCR_LDBG(x)                        (((uint32_t)(((uint32_t)(x)) << ESCI_LCR_LDBG_SHIFT)) & ESCI_LCR_LDBG_MASK)
#define ESCI_LCR_DSF_SHIFT                      (0x1Au)
#define ESCI_LCR_DSF_MASK                       (0x01u << ESCI_LCR_DSF_SHIFT)
#define ESCI_LCR_DSF(x)                         (((uint32_t)(((uint32_t)(x)) << ESCI_LCR_DSF_SHIFT)) & ESCI_LCR_DSF_MASK)
#define ESCI_LCR_PRTY_SHIFT                     (0x19u)
#define ESCI_LCR_PRTY_MASK                      (0x01u << ESCI_LCR_PRTY_SHIFT)
#define ESCI_LCR_PRTY(x)                        (((uint32_t)(((uint32_t)(x)) << ESCI_LCR_PRTY_SHIFT)) & ESCI_LCR_PRTY_MASK)
#define ESCI_LCR_LIN_SHIFT                      (0x18u)
#define ESCI_LCR_LIN_MASK                       (0x01u << ESCI_LCR_LIN_SHIFT)
#define ESCI_LCR_LIN(x)                         (((uint32_t)(((uint32_t)(x)) << ESCI_LCR_LIN_SHIFT)) & ESCI_LCR_LIN_MASK)
#define ESCI_LCR_RXIE_SHIFT                     (0x17u)
#define ESCI_LCR_RXIE_MASK                      (0x01u << ESCI_LCR_RXIE_SHIFT)
#define ESCI_LCR_RXIE(x)                        (((uint32_t)(((uint32_t)(x)) << ESCI_LCR_RXIE_SHIFT)) & ESCI_LCR_RXIE_MASK)
#define ESCI_LCR_TXIE_SHIFT                     (0x16u)
#define ESCI_LCR_TXIE_MASK                      (0x01u << ESCI_LCR_TXIE_SHIFT)
#define ESCI_LCR_TXIE(x)                        (((uint32_t)(((uint32_t)(x)) << ESCI_LCR_TXIE_SHIFT)) & ESCI_LCR_TXIE_MASK)
#define ESCI_LCR_WUIE_SHIFT                     (0x15u)
#define ESCI_LCR_WUIE_MASK                      (0x01u << ESCI_LCR_WUIE_SHIFT)
#define ESCI_LCR_WUIE(x)                        (((uint32_t)(((uint32_t)(x)) << ESCI_LCR_WUIE_SHIFT)) & ESCI_LCR_WUIE_MASK)
#define ESCI_LCR_STIE_SHIFT                     (0x14u)
#define ESCI_LCR_STIE_MASK                      (0x01u << ESCI_LCR_STIE_SHIFT)
#define ESCI_LCR_STIE(x)                        (((uint32_t)(((uint32_t)(x)) << ESCI_LCR_STIE_SHIFT)) & ESCI_LCR_STIE_MASK)
#define ESCI_LCR_PBIE_SHIFT                     (0x13u)
#define ESCI_LCR_PBIE_MASK                      (0x01u << ESCI_LCR_PBIE_SHIFT)
#define ESCI_LCR_PBIE(x)                        (((uint32_t)(((uint32_t)(x)) << ESCI_LCR_PBIE_SHIFT)) & ESCI_LCR_PBIE_MASK)
#define ESCI_LCR_CIE_SHIFT                      (0x12u)
#define ESCI_LCR_CIE_MASK                       (0x01u << ESCI_LCR_CIE_SHIFT)
#define ESCI_LCR_CIE(x)                         (((uint32_t)(((uint32_t)(x)) << ESCI_LCR_CIE_SHIFT)) & ESCI_LCR_CIE_MASK)
#define ESCI_LCR_CKIE_SHIFT                     (0x11u)
#define ESCI_LCR_CKIE_MASK                      (0x01u << ESCI_LCR_CKIE_SHIFT)
#define ESCI_LCR_CKIE(x)                        (((uint32_t)(((uint32_t)(x)) << ESCI_LCR_CKIE_SHIFT)) & ESCI_LCR_CKIE_MASK)
#define ESCI_LCR_FCIE_SHIFT                     (0x10u)
#define ESCI_LCR_FCIE_MASK                      (0x01u << ESCI_LCR_FCIE_SHIFT)
#define ESCI_LCR_FCIE(x)                        (((uint32_t)(((uint32_t)(x)) << ESCI_LCR_FCIE_SHIFT)) & ESCI_LCR_FCIE_MASK)
#define ESCI_LCR_UQIE_SHIFT                     (0x09u)
#define ESCI_LCR_UQIE_MASK                      (0x01u << ESCI_LCR_UQIE_SHIFT)
#define ESCI_LCR_UQIE(x)                        (((uint32_t)(((uint32_t)(x)) << ESCI_LCR_UQIE_SHIFT)) & ESCI_LCR_UQIE_MASK)
#define ESCI_LCR_OFIE_SHIFT                     (0x08u)
#define ESCI_LCR_OFIE_MASK                      (0x01u << ESCI_LCR_OFIE_SHIFT)
#define ESCI_LCR_OFIE(x)                        (((uint32_t)(((uint32_t)(x)) << ESCI_LCR_OFIE_SHIFT)) & ESCI_LCR_OFIE_MASK)

/*! @name LTR - ESCI LIN Transmit Register */
/*! @name LRR - ESCI LIN Receive Register */
/*! @name LPR - ESCI CRC Polynomial Register */

/*!
 * @}
 */ /* end of group ESCI_Register_Masks */

/* eSCI - Peripheral instance base addresses */
/** Peripheral eSCI base address */
#define ESCI_BASE                                (0xFFFA0000u)
/** Peripheral eSCI_A base address */
#define ESCIA_BASE                               (ESCI_BASE + 0x0000)
/** Peripheral eSCI_A base pointer */
#define ESCIA                                    ((ESCI_Type *)ESCIA_BASE)
/** Peripheral eSCI_B base address */
#define ESCIB_BASE                               (ESCI_BASE + 0x4000)
/** Peripheral eSCI_B base pointer */
#define ESCIB                                    ((ESCI_Type *)ESCIB_BASE)
/** Peripheral eSCI_C base address */
#define ESCIC_BASE                               (ESCI_BASE + 0x8000)
/** Peripheral eSCI_C base pointer */
#define ESCIC                                    ((ESCI_Type *)ESCIC_BASE)
/** Peripheral eSCI_D base address */
#define ESCID_BASE                               (ESCI_BASE + 0xC000)
/** Peripheral eSCI_D base pointer */
#define ESCID                                    ((ESCI_Type *)ESCID_BASE)
/** Peripheral eSCI_E base address */
#define ESCIE_BASE                               (ESCI_BASE + 0x10000)
/** Peripheral eSCI_E base pointer */
#define ESCIE                                    ((ESCI_Type *)ESCIE_BASE)
/** Peripheral eSCI_F base address */
#define ESCIF_BASE                               (ESCI_BASE + 0x14000)
/** Peripheral eSCI_F base pointer */
#define ESCIF                                    ((ESCI_Type *)ESCIF_BASE)
/** Peripheral eSCI_G base address */
#define ESCIG_BASE                               (ESCI_BASE + 0x18000)
/** Peripheral eSCI_G base pointer */
#define ESCIG                                    ((ESCI_Type *)ESCIG_BASE)
/** Peripheral eSCI_H base address */
#define ESCIH_BASE                               (ESCI_BASE + 0x1C000)
/** Peripheral eSCI_H base pointer */   
#define ESCIH                                    ((ESCI_Type *)ESCIH_BASE)
