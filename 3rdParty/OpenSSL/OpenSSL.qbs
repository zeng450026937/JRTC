import qbs
import qbs.File
import qbs.FileInfo

Product {
    name: "OpenSSL"
    type: "staticlibrary"

    Depends {
        name: "cpp"
    }
    cpp.includePaths: [
        "src",
        "src/ssl",
        "src/crypto",
        "src/crypto/asn1",
        "src/crypto/evp",
        "src/crypto/modes",
        qbs.installRoot
    ]
    cpp.defines: [
            "OPENSSL_NO_ASM",
            "OPENSSL_NO_GMP",
            "OPENSSL_NO_JPAKE",
            "OPENSSL_NO_KRB5",
            "OPENSSL_NO_MD2",
            "OPENSSL_NO_RFC3779",
            "OPENSSL_NO_STORE",
            "OPENSSL_NO_DYNAMIC_ENGINE",
            "OPENSSL_NO_SCTP",
            "OPENSSL_NO_EC_NISTP_64_GCC_128"
    ] 
    Properties {
        condition: qbs.targetOS.contains("windows")
        cpp.defines: outer.concat([
            "OPENSSL_SYSNAME_WIN32",
            "WIN32_LEAN_AND_MEAN"
        ])
    }

    Group {
        name: "global"
        prefix: "src/"
        files: ["buildinf.h","e_os2.h"]
    }
    Group {
        id: crypto
        name: "crypto"
        prefix: "src/crypto/"
        files: [
            "crypto.h",
            "opensslv.h",
            "opensslconf.h",
            "ebcdic.h",
            "symhacks.h",
            "ossl_typ.h",
            "cryptlib.c",
            "mem.c",
            "mem_clr.c",
            "mem_dbg.c",
            "cversion.c",
            "ex_data.c",
            "cpt_err.c",
            "ebcdic.c",
            "uid.c",
            "o_time.c",
            "o_str.c",
            "o_dir.c",
            "o_init.c"
        ]
        Group {
            id: engines
            name: "engines"
            prefix: "src/engines/"
            files: [
                "e_4758cca.c",
                "e_aep.c",
                "e_atalla.c",
                "e_cswift.c",
                "e_gmp.c",
                "e_chil.c",
                "e_nuron.c",
                "e_sureware.c",
                "e_ubsec.c",
                "e_padlock.c",
                "e_capi.c"
            ]
            Group {
                name: "ccgost"
                prefix: engines.prefix + "ccgost/"
                files: [
                    "e_gost_err.c",
                    "gost2001.c",
                    "gost2001_keyx.c",
                    "gost89.c",
                    "gost94_keyx.c",
                    "gost_ameth.c",
                    "gost_asn1.c",
                    "gost_crypt.c",
                    "gost_ctl.c",
                    "gost_eng.c",
                    "gosthash.c",
                    "gost_keywrap.c",
                    "gost_md.c",
                    "gost_params.c",
                    "gost_pmeth.c",
                    "gost_sign.c"
                ]
            }
        }
        Group {
            name: "aes"
            prefix: crypto.prefix + "aes/"
            files:[
                "aes_core.c",
                "aes_misc.c",
                "aes_ecb.c",
                "aes_cbc.c",
                "aes_cfb.c",
                "aes_ofb.c",
                "aes_ctr.c",
                "aes_ige.c",
                "aes_wrap.c",
                "aes.h"
            ]
        }
        Group {
            name: "asn1"
            prefix: crypto.prefix + "asn1/"
            files:[
                "a_object.c",
                "a_bitstr.c",
                "a_utctm.c",
                "a_gentm.c",
                "a_time.c",
                "a_int.c",
                "a_octet.c",
                "a_print.c",
                "a_type.c",
                "a_set.c",
                "a_dup.c",
                "a_d2i_fp.c",
                "a_i2d_fp.c",
                "a_enum.c",
                "a_utf8.c",
                "a_sign.c",
                "a_digest.c",
                "a_verify.c",
                "a_mbstr.c",
                "a_strex.c",
                "x_algor.c",
                "x_val.c",
                "x_pubkey.c",
                "x_sig.c",
                "x_req.c",
                "x_attrib.c",
                "x_bignum.c",
                "x_long.c",
                "x_name.c",
                "x_x509.c",
                "x_x509a.c",
                "x_crl.c",
                "x_info.c",
                "x_spki.c",
                "nsseq.c",
                "x_nx509.c",
                "d2i_pu.c",
                "d2i_pr.c",
                "i2d_pu.c",
                "i2d_pr.c",
                "t_req.c",
                "t_x509.c",
                "t_x509a.c",
                "t_crl.c",
                "t_pkey.c",
                "t_spki.c",
                "t_bitst.c",
                "tasn_new.c",
                "tasn_fre.c",
                "tasn_enc.c",
                "tasn_dec.c",
                "tasn_utl.c",
                "tasn_typ.c",
                "tasn_prn.c",
                "ameth_lib.c",
                "f_int.c",
                "f_string.c",
                "n_pkey.c",
                "f_enum.c",
                "x_pkey.c",
                "a_bool.c",
                "x_exten.c",
                "bio_asn1.c",
                "bio_ndef.c",
                "asn_mime.c",
                "asn1_gen.c",
                "asn1_par.c",
                "asn1_lib.c",
                "asn1_err.c",
                "a_bytes.c",
                "a_strnid.c",
                "evp_asn1.c",
                "asn_pack.c",
                "p5_pbe.c",
                "p5_pbev2.c",
                "p8_pkey.c",
                "asn_moid.c",
                "asn1.h",
                "asn1_mac.h",
                "asn1t.h"
            ]
        }
        Group {
            name: "bf"
            prefix: crypto.prefix + "bf/"
            files:[
                "bf_skey.c",
                "bf_ecb.c",
                "bf_enc.c",
                "bf_cfb64.c",
                "bf_ofb64.c",
                "blowfish.h"
            ]
        }
        Group {
            name: "bio"
            prefix: crypto.prefix + "bio/"
            files:[
                "bio_lib.c",
                "bio_cb.c",
                "bio_err.c",
                "bss_mem.c",
                "bss_null.c",
                "bss_fd.c",
                "bss_file.c",
                "bss_sock.c",
                "bss_conn.c",
                "bf_null.c",
                "bf_buff.c",
                "b_print.c",
                "b_dump.c",
                "b_sock.c",
                "bss_acpt.c",
                "bf_nbio.c",
                "bss_log.c",
                "bss_bio.c",
                "bss_dgram.c",
                //"bf_lbuf.c",
                "bio.h"
            ]
        }
        Group {
            name: "bn"
            prefix: crypto.prefix + "bn/"
            files:[
                "bn_add.c",
                "bn_div.c",
                "bn_exp.c",
                "bn_lib.c",
                "bn_ctx.c",
                "bn_mul.c",
                "bn_mod.c",
                "bn_print.c",
                "bn_rand.c",
                "bn_shift.c",
                "bn_word.c",
                "bn_blind.c",
                "bn_kron.c",
                "bn_sqrt.c",
                "bn_gcd.c",
                "bn_prime.c",
                "bn_err.c",
                "bn_sqr.c",
                "bn_asm.c",
                "bn_recp.c",
                "bn_mont.c",
                "bn_mpi.c",
                "bn_exp2.c",
                "bn_gf2m.c",
                "bn_nist.c",
                "bn_depr.c",
                "bn_const.c",
                "bn.h"
            ]
        }
        Group {
            name: "buffer"
            prefix: crypto.prefix + "buffer/"
            files:[
                "buffer.c",
                "buf_err.c",
                "buf_str.c",
                "buffer.h"
            ]
        }
        Group {
            name: "camellia"
            prefix: crypto.prefix + "camellia/"
            files:[
                "camellia.c",
                "cmll_misc.c",
                "cmll_ecb.c",
                "cmll_cbc.c",
                "cmll_ofb.c",
                "cmll_cfb.c",
                "cmll_ctr.c",
                "cmll_utl.c",
                "camellia.h"
            ]
        }
        Group {
            name: "cast"
            prefix: crypto.prefix + "cast/"
            files:[
                "c_skey.c",
                "c_ecb.c",
                "c_enc.c",
                "c_cfb64.c",
                "c_ofb64.c",
                "cast.h"
            ]
        }
        Group {
            name: "cmac"
            prefix: crypto.prefix + "cmac/"
            files:[
                "cm_ameth.c",
                "cm_pmeth.c",
                "cmac.c",
                "cmac.h"
            ]
        }
        Group {
            name: "cms"
            prefix: crypto.prefix + "cms/"
            files:[
                "cms_lib.c",
                "cms_asn1.c",
                "cms_att.c",
                "cms_io.c",
                "cms_smime.c",
                "cms_err.c",
                "cms_sd.c",
                "cms_dd.c",
                "cms_cd.c",
                "cms_env.c",
                "cms_enc.c",
                "cms_ess.c",
                "cms_pwri.c",
                "cms.h"
            ]
        }
        Group {
            name: "comp"
            prefix: crypto.prefix + "comp/"
            files:[
                "comp_lib.c",
                "comp_err.c",
                "c_rle.c",
                "c_zlib.c",
                "comp.h"
            ]
        }
        Group {
            name: "conf"
            prefix: crypto.prefix + "conf/"
            files:[
                "conf_err.c",
                "conf_lib.c",
                "conf_api.c",
                "conf_def.c",
                "conf_mod.c",
                "conf_mall.c",
                "conf_sap.c",
                "conf.h",
                "conf_api.h"
            ]
        }
        Group {
            name: "des"
            prefix: crypto.prefix + "des/"
            files:[
                "cbc_cksm.c",
                "cbc_enc.c",
                "cfb64enc.c",
                "cfb_enc.c",
                "ecb3_enc.c",
                "ecb_enc.c",
                "enc_read.c",
                "enc_writ.c",
                "fcrypt.c",
                "ofb64enc.c",
                "ofb_enc.c",
                "pcbc_enc.c",
                "qud_cksm.c",
                "rand_key.c",
                "rpc_enc.c",
                "set_key.c",
                "des_enc.c",
                "fcrypt_b.c",
                "xcbc_enc.c",
                "str2key.c",
                "cfb64ede.c",
                "ofb64ede.c",
                "ede_cbcm_enc.c",
                "des_old.c",
                "des_old2.c",
                "read2pwd.c",
                "des.h",
                "des_old.h"
            ]
        }
        Group {
            name: "dh"
            prefix: crypto.prefix + "dh/"
            files:[
                "dh_asn1.c",
                "dh_gen.c",
                "dh_key.c",
                "dh_lib.c",
                "dh_check.c",
                "dh_err.c",
                "dh_depr.c",
                "dh_ameth.c",
                "dh_pmeth.c",
                "dh_prn.c",
                "dh.h"
            ]
        }
        Group {
            name: "dsa"
            prefix: crypto.prefix + "dsa/"
            files:[
                "dsa_gen.c",
                "dsa_key.c",
                "dsa_lib.c",
                "dsa_asn1.c",
                "dsa_vrf.c",
                "dsa_sign.c",
                "dsa_err.c",
                "dsa_ossl.c",
                "dsa_depr.c",
                "dsa_ameth.c",
                "dsa_pmeth.c",
                "dsa_prn.c",
                "dsa.h"
            ]
        }
        Group {
            name: "dso"
            prefix: crypto.prefix + "dso/"
            files:[
                "dso_dl.c",
                "dso_dlfcn.c",
                "dso_err.c",
                "dso_lib.c",
                "dso_null.c",
                "dso_openssl.c",
                "dso_win32.c",
                "dso_vms.c",
                "dso_beos.c",
                "dso.h"
            ]
        }
        Group {
            name: "ec"
            prefix: crypto.prefix + "ec/"
            files:[
                "ec_lib.c",
				"ecp_smpl.c",
				"ecp_mont.c",
				"ecp_nist.c",
				"ec_cvt.c",
				"ec_mult.c",
				"ec_err.c",
				"ec_curve.c",
				"ec_check.c",
				"ec_print.c",
				"ec_asn1.c",
				"ec_key.c",
				"ec2_smpl.c",
				"ec2_mult.c",
				"ec_ameth.c",
				"ec_oct.c",
				"ec_pmeth.c",
				"eck_prn.c",
				"ecp_oct.c",
				"ec2_oct.c",
				"ec.h"
            ]
        }
        Group {
            name: "ecdh"
            prefix: crypto.prefix + "ecdh/"
            files:[
                "ech_lib.c",
				"ech_ossl.c",
				"ech_key.c",
				"ech_err.c",
				"ecdh.h"
            ]
        }
        Group {
            name: "ecdsa"
            prefix: crypto.prefix + "ecdsa/"
            files:[
                "ecs_lib.c",
				"ecs_asn1.c",
				"ecs_ossl.c",
				"ecs_sign.c",
				"ecs_vrf.c",
				"ecs_err.c",
				"ecdsa.h"
            ]
        }
        Group {
            name: "engine"
            prefix: crypto.prefix + "engine/"
            files:[
                "eng_err.c",
				"eng_lib.c",
				"eng_list.c",
				"eng_init.c",
				"eng_ctrl.c",
				"eng_table.c",
				"eng_pkey.c",
				"eng_fat.c",
				"eng_all.c",
				"tb_rsa.c",
				"tb_dsa.c",
				"tb_ecdsa.c",
				"tb_dh.c",
				"tb_ecdh.c",
				"tb_rand.c",
				"tb_store.c",
				"tb_cipher.c",
				"tb_digest.c",
				"tb_pkmeth.c",
				"tb_asnmth.c",
				"eng_openssl.c",
				"eng_cnf.c",
				"eng_dyn.c",
				"eng_cryptodev.c",
				"eng_rdrand.c",
				"eng_rsax.c",
				"engine.h"
            ]
        }
        Group {
            name: "err"
            prefix: crypto.prefix + "err/"
            files:[
                "err.c",
				"err_all.c",
				"err_prn.c",
				"err.h"
            ]
        }
        Group {
            name: "evp"
            prefix: crypto.prefix + "evp/"
            files:[
                "encode.c",
				"digest.c",
				"evp_enc.c",
				"evp_key.c",
				"evp_acnf.c",
				"e_des.c",
				"e_bf.c",
				"e_idea.c",
				"e_des3.c",
				"e_camellia.c",
				"e_rc4.c",
				"e_aes.c",
				"names.c",
				"e_seed.c",
				"e_xcbc_d.c",
				"e_rc2.c",
				"e_cast.c",
				"e_rc5.c",
				"m_null.c",
				"m_md2.c",
				"m_md4.c",
				"m_md5.c",
				"m_sha.c",
				"m_sha1.c",
				"m_wp.c",
				"m_dss.c",
				"m_dss1.c",
				"m_mdc2.c",
				"m_ripemd.c",
				"m_ecdsa.c",
				"p_open.c",
				"p_seal.c",
				"p_sign.c",
				"p_verify.c",
				"p_lib.c",
				"p_enc.c",
				"p_dec.c",
				"bio_md.c",
				"bio_b64.c",
				"bio_enc.c",
				"evp_err.c",
				"e_null.c",
				"c_all.c",
				"c_allc.c",
				"c_alld.c",
				"evp_lib.c",
				"bio_ok.c",
				"evp_pkey.c",
				"evp_pbe.c",
				"p5_crpt.c",
				"p5_crpt2.c",
				"e_old.c",
				"pmeth_lib.c",
				"pmeth_fn.c",
				"pmeth_gn.c",
				"m_sigver.c",
				"evp_cnf.c",
				"e_rc4_hmac_md5.c",
				"e_aes_cbc_hmac_sha1.c",
				"evp.h"
            ]
        }
        Group {
            name: "hmac"
            prefix: crypto.prefix + "hmac/"
            files:[
                "hmac.c",
				"hm_ameth.c",
				"hm_pmeth.c",
				"hmac.h"
            ]
        }
        Group {
            name: "idea"
            prefix: crypto.prefix + "idea/"
            files:[
                "i_cbc.c",
				"i_cfb64.c",
				"i_ofb64.c",
				"i_ecb.c",
				"i_skey.c",
				"idea.h"
            ]
        }
        Group {
            name: "krb5"
            prefix: crypto.prefix + "krb5/"
            files:[
                "krb5_asn.c",
				"krb5_asn.h"
            ]
        }
        Group {
            name: "lhash"
            prefix: crypto.prefix + "lhash/"
            files:[
                "lhash.c",
				"lh_stats.c",
				"lhash.h"
            ]
        }
        Group {
            name: "md4"
            prefix: crypto.prefix + "md4/"
            files:[
                "md4_dgst.c",
				"md4_one.c",
				"md4.h"
            ]
        }
        Group {
            name: "md5"
            prefix: crypto.prefix + "md5/"
            files:[
                "md5_dgst.c",
				"md5_one.c",
				"md5.h"
            ]
        }
        Group {
            name: "mdc2"
            prefix: crypto.prefix + "mdc2/"
            files:[
                "mdc2dgst.c",
				"mdc2_one.c",
				"mdc2.h"
            ]
        }
        Group {
            name: "modes"
            prefix: crypto.prefix + "modes/"
            files:[
                "cbc128.c",
				"ccm128.c",
				"ctr128.c",
				"cts128.c",
				"cfb128.c",
				"gcm128.c",
				"ofb128.c",
                "xts128.c",
				"modes.h"
            ]
        }
        Group {
            name: "objects"
            prefix: crypto.prefix + "objects/"
            files:[
                "o_names.c",
				"obj_dat.c",
				"obj_lib.c",
				"obj_err.c",
				"obj_xref.c",
                "objects.h",
				"obj_mac.h"
            ]
        }
        Group {
            name: "ocsp"
            prefix: crypto.prefix + "ocsp/"
            files:[
                "ocsp_asn.c",
				"ocsp_ext.c",
				"ocsp_ht.c",
				"ocsp_lib.c",
				"ocsp_cl.c",
				"ocsp_srv.c",
                "ocsp_prn.c",
				"ocsp_vfy.c",
				"ocsp_err.c",
				"ocsp.h"
            ]
        }
        Group {
            name: "pem"
            prefix: crypto.prefix + "pem/"
            files:[
                "pem_sign.c",
				"pem_seal.c",
				"pem_info.c",
				"pem_lib.c",
				"pem_all.c",
				"pem_err.c",
                "pem_x509.c",
				"pem_xaux.c",
				"pem_oth.c",
				"pem_pk8.c",
				"pem_pkey.c",
				"pvkfmt.c",
				"pem.h",
                "pem2.h"
            ]
        }
        Group {
            name: "pkcs12"
            prefix: crypto.prefix + "pkcs12/"
            files:[
                "p12_add.c",
				"p12_asn.c",
				"p12_attr.c",
				"p12_crpt.c",
				"p12_crt.c",
				"p12_decr.c",
                "p12_init.c",
				"p12_key.c",
				"p12_kiss.c",
				"p12_mutl.c",
				"p12_utl.c",
				"p12_npas.c",
				"pk12err.c",
				"p12_p8d.c",
                "p12_p8e.c",
				"pkcs12.h"
            ]
        }
        Group {
            name: "pkcs7"
            prefix: crypto.prefix + "pkcs7/"
            files:[
                "pk7_asn1.c",
				"pk7_lib.c",
				"pkcs7err.c",
				"pk7_doit.c",
				"pk7_smime.c",
				"pk7_attr.c",
                "pk7_mime.c",
				"bio_pk7.c",
				"pkcs7.h"
            ]
        }
        Group {
            name: "pqueue"
            prefix: crypto.prefix + "pqueue/"
            files:[
                "pqueue.c",
				"pqueue.h"
            ]
        }
        Group {
            name: "rand"
            prefix: crypto.prefix + "rand/"
            files:[
                "md_rand.c",
				"randfile.c",
				"rand_lib.c",
				"rand_err.c",
				"rand_egd.c",
				"rand_win.c",
                "rand_unix.c",
				"rand_os2.c",
				"rand_nw.c",
				"rand.h"
            ]
        }
        Group {
            name: "rc2"
            prefix: crypto.prefix + "rc2/"
            files:[
                "rc2_ecb.c",
				"rc2_skey.c",
				"rc2_cbc.c",
				"rc2cfb64.c",
				"rc2ofb64.c",
				"rc2.h"
            ]
        }
        Group {
            name: "rc4"
            prefix: crypto.prefix + "rc4/"
            files:[
                "rc4_skey.c",
				"rc4_enc.c",
				"rc4_utl.c",
				"rc4.h"
            ]
        }
        Group {
            name: "rc5"
            prefix: crypto.prefix + "rc5/"
            files:[
                "rc5_skey.c",
				"rc5_ecb.c",
				"rc5_enc.c",
				"rc5cfb64.c",
				"rc5ofb64.c",
                "rc5.h"
            ]
        }
        Group {
            name: "ripemd"
            prefix: crypto.prefix + "ripemd/"
            files:[
                "rmd_dgst.c",
				"rmd_one.c",
				"ripemd.h"
            ]
        }
        Group {
            name: "rsa"
            prefix: crypto.prefix + "rsa/"
            files:[
                "rsa_eay.c",
				"rsa_gen.c",
				"rsa_lib.c",
				"rsa_sign.c",
				"rsa_saos.c",
				"rsa_err.c",
				"rsa_pk1.c",
				"rsa_ssl.c",
				"rsa_none.c",
				"rsa_oaep.c",
				"rsa_chk.c",
				"rsa_null.c",
				"rsa_pss.c",
				"rsa_x931.c",
				"rsa_asn1.c",
				"rsa_depr.c",
				"rsa_ameth.c",
				"rsa_prn.c",
				"rsa_pmeth.c",
				"rsa_crpt.c",
				"rsa.h"
            ]
        }
        Group {
            name: "seed"
            prefix: crypto.prefix + "seed/"
            files:[
                "seed.c",
				"seed_ecb.c",
				"seed_cbc.c",
				"seed_cfb.c",
				"seed_ofb.c",
				"seed.h"
            ]
        }
        Group {
            name: "sha"
            prefix: crypto.prefix + "sha/"
            files:[
                "sha_dgst.c",
				"sha1dgst.c",
				"sha_one.c",
				"sha1_one.c",
				"sha256.c",
				"sha512.c",
				"sha.h"
            ]
        }
        Group {
            name: "srp"
            prefix: crypto.prefix + "srp/"
            files:[
                "srp_lib.c",
				"srp_vfy.c",
				"srp.h",
                "srp_grps.h",
                "srp_lcl.h"
            ]
        }
        Group {
            name: "stack"
            prefix: crypto.prefix + "stack/"
            files:[
                "stack.c",
				"stack.h",
                "safestack.h"
            ]
        }
        /*
        Group {
            name: "store"
            prefix: crypto.prefix + "store/"
            files:[
                "str_err.c",
				"str_lib.c",
				"str_meth.c",
				"str_mem.c",
				"store.h"
            ]
        }
        */
        Group {
            name: "ts"
            prefix: crypto.prefix + "ts/"
            files:[
                "ts_err.c",
				"ts_req_utils.c",
				"ts_req_print.c",
				"ts_rsp_utils.c",
				"ts_rsp_print.c",
                "ts_rsp_sign.c",
				"ts_rsp_verify.c",
				"ts_verify_ctx.c",
				"ts_lib.c",
				"ts_conf.c",
				"ts_asn1.c",
				"ts.h"
            ]
        }
        Group {
            name: "txt_db"
            prefix: crypto.prefix + "txt_db/"
            files:[
                "txt_db.c",
				"txt_db.h"
            ]
        }
        Group {
            name: "ui"
            prefix: crypto.prefix + "ui/"
            files:[
                "ui_err.c",
				"ui_lib.c",
				"ui_openssl.c",
				"ui_util.c",
				"ui_compat.c",
				"ui.h",
                "ui_compat.h"
            ]
        }
        Group {
            name: "whrlpool"
            prefix: crypto.prefix + "whrlpool/"
            files:[
                "wp_dgst.c",
				"wp_block.c",
				"whrlpool.h"
            ]
        }
        Group {
            name: "x509"
            prefix: crypto.prefix + "x509/"
            files:[
                "x509_def.c",
				"x509_d2.c",
				"x509_r2x.c",
				"x509_cmp.c",
				"x509_obj.c",
				"x509_req.c",
				"x509spki.c",
				"x509_vfy.c",
				"x509_set.c",
				"x509cset.c",
				"x509rset.c",
				"x509_err.c",
				"x509name.c",
				"x509_v3.c",
				"x509_ext.c",
				"x509_att.c",
				"x509type.c",
				"x509_lu.c",
				"x_all.c",
				"x509_txt.c",
				"x509_trs.c",
				"by_file.c",
				"by_dir.c",
				"x509_vpm.c",
				"x509.h",
                "x509_vfy.h"
            ]
        }
        Group {
            name: "x509v3"
            prefix: crypto.prefix + "x509v3/"
            files:[
                "v3_bcons.c",
				"v3_bitst.c",
				"v3_conf.c",
				"v3_extku.c",
				"v3_ia5.c",
				"v3_lib.c",
				"v3_prn.c",
				"v3_utl.c",
				"v3err.c",
				"v3_genn.c",
				"v3_alt.c",
				"v3_skey.c",
				"v3_akey.c",
				"v3_pku.c",
				"v3_int.c",
				"v3_enum.c",
				"v3_sxnet.c",
				"v3_cpols.c",
				"v3_crld.c",
				"v3_purp.c",
				"v3_info.c",
				"v3_ocsp.c",
				"v3_akeya.c",
				"v3_pmaps.c",
				"v3_pcons.c",
				"v3_ncons.c",
				"v3_pcia.c",
				"v3_pci.c",
				"pcy_cache.c",
				"pcy_node.c",
				"pcy_data.c",
				"pcy_map.c",
				"pcy_tree.c",
				"pcy_lib.c",
				"v3_asid.c",
				"v3_addr.c",
                "x509v3.h"
            ]
        }

        cpp.defines: {
            var defines = outer.concat(["OPENSSL_THREADS"])
            if (qbs.targetOS.contains("windows")) {
                defines.concat(["HEADER_OCSP_H"])

                if (qbs.toolchain.contains("mingw"))
                    defines.concat(["DSO_WIN32","OPENSSL_EXPORT_VAR_AS_FUNCTION"])
            }
            if (product.type == "dynamiclibrary")
                defines.concat(["OPENSSL_BUILD_SHLIBCRYPTO"])
            return defines;

            console.info("cpp.defines in crypto\n" + defines)
        }
    }
    Group {
        name: "ssl"
        prefix: "src/ssl/"
        files: [
            // header files
            "ssl.h",
            "kssl.h",
            "ssl2.h",
            "ssl3.h",
            "tls1.h",
            "dtls1.h",
            "ssl23.h",
            "srtp.h",
            // source files
            "s2_meth.c",
            "s2_srvr.c",
            "s2_clnt.c",
            "s2_lib.c",
            "s2_enc.c",
            "s2_pkt.c",
            "s3_meth.c",
            "s3_srvr.c",
            "s3_clnt.c",
            "s3_lib.c",
            "s3_enc.c",
            "s3_pkt.c",
            "s3_both.c",
            "s23_meth.c",
            "s23_srvr.c",
            "s23_clnt.c",
            "s23_lib.c",
            "s23_pkt.c",
            "t1_meth.c",
            "t1_srvr.c",
            "t1_clnt.c",
            "t1_lib.c",
            "t1_enc.c",
            "d1_meth.c",
            "d1_srvr.c",
            "d1_clnt.c",
            "d1_lib.c",
            "d1_pkt.c",
            "d1_both.c",
            "d1_enc.c",
            "ssl_lib.c",
            "ssl_err2.c",
            "ssl_cert.c",
            "ssl_sess.c",
            "ssl_ciph.c",
            "ssl_stat.c",
            "ssl_rsa.c",
            "ssl_asn1.c",
            "ssl_txt.c",
            "ssl_algs.c",
            "bio_ssl.c",
            "ssl_err.c",
            "kssl.c",
            "t1_reneg.c",
            "tls_srp.c",
            "s3_cbc.c",
            "d1_srtp.c"
        ]
        
        cpp.defines: {
            var defines = outer
            if (product.type == "dynamiclibrary")
                defines.concat(["OPENSSL_BUILD_SHLIBSSL"])
            return defines;
        }
    }

    Export {
        Depends {
            name: "cpp"
        }
        cpp.defines: ["HAVE_" + product.name.toUpperCase()]
        cpp.includePaths: [qbs.installRoot]
    }

    Group {
        qbs.install: true
        fileTagsFilter: product.type
    }
    Group {
        qbs.install: true
        qbs.installDir: "openssl"
        fileTagsFilter: "hpp"
    }
}